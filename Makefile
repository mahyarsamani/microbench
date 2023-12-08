
SRCDIRS=$(shell find . -type d)
SOURCES=$(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))

RAND_DIRS=$(shell find . -name "rand_arr_args.txt" -exec dirname {} \;)


CC=gcc
OPT=-O2
ROI_DIR=$(PWD)/../roi

all: native papi gem5

rand_arr:
	@for dir in $(RAND_DIRS); do \
		cd $$dir && if [ ! -f randArr.h ]; then python3 ../rand_c_arr.py $$(cat rand_arr_args.txt); fi; \
		cd - > /dev/null; \
	done

native: rand_arr $(SOURCES:.c=.native)
papi: rand_arr $(SOURCES:.c=.papi)
gem5: rand_arr $(SOURCES:.c=.gem5)

%.native: %.c
	$(CC) -o $@ $< --static --std=c99 $(OPT) -I$(ROI_DIR)/include -L$(ROI_DIR)/lib -lm -lroi.native

%.papi: %.c
	$(CC) -o $@ $< --static --std=c99 $(OPT) -I$(ROI_DIR)/include -I$(ROI_DIR)/papi/install/include -L$(ROI_DIR)/lib -L$(ROI_DIR)/papi/install/lib -lm -lroi.papi -lpapi -lpthread

%.gem5: %.c
	$(CC) -o $@ $< --static --std=c99 $(OPT) -I$(ROI_DIR)/include -I$(ROI_DIR)/gem5/include -L$(ROI_DIR)/lib -L$(ROI_DIR)/gem5/lib -lm -lroi.gem5 -lm5

clean:
	rm -f $(SOURCES:.c=.native) $(SOURCES:.c=.papi) $(SOURCES:.c=.gem5)  */randArr.h

clean-native:
	rm -f $(SOURCES:.c=.native)

clean-papi:
	rm -f $(SOURCES:.c=.papi)

clean-gem5:
	rm -f $(SOURCES:.c=.gem5)

.PHONY: all native papi gem5 rand_arr clean clean-native clean-papi clean-gem5
