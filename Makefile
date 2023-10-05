
include make.config

SRCDIRS=$(shell find . -type d)
SOURCES=$(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))

RAND_DIRS=$(shell find . -name "rand_arr_args.txt" -exec dirname {} \;)


CC=gcc

all: native papi gem5

rand_arr:
	@for dir in $(RAND_DIRS); do \
		cd $$dir && if [ ! -f randArr.h ]; then python ../rand_c_arr.py $$(cat rand_arr_args.txt); fi; \
		cd - > /dev/null; \
	done

native: rand_arr $(SOURCES:.c=.native)
papi: rand_arr $(SOURCES:.c=.papi)
gem5: rand_arr $(SOURCES:.c=.gem5)

%.native: %.c
	$(CC) $< -o $@ -Iinclude -lm -O0 --static --std=c99

%.papi: %.c
	$(CC) $< -o $@ -DPAPI -Iinclude -I../papi/install/include -L../papi/install/lib -lm -lpapi -O0 --static --std=c99

%.gem5: %.c
	$(CC) $< -o $@ -DGEM5 -Iinclude -Llib/m5/arm64 -lm -lm5 -O0 --static --std=c99

clean:
	rm -f $(SOURCES:.c=.native) $(SOURCES:.c=.papi) $(SOURCES:.c=.gem5) */randArr.h

.PHONY: all native papi gem5 rand_arr clean
