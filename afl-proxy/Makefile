SUBDIRS := proxy aplib

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  SUBDIRS += send
endif
ifeq ($(UNAME_S),Darwin)
  LDFLAGS += 
endif

all: $(SUBDIRS) stage2

stage2:
	cd stage2 && ./build.sh build && cd ..

$(SUBDIRS):
	$(MAKE) -C $@

.PHONY: all $(SUBDIRS) stage2

clean: clean_stage2
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
	done 

clean_stage2:
	cd stage2 && ./build.sh clean && cd ..

indent:
	clang-format -i -style=file `find $d -name '*.cpp' -or -name "*.h" -or -name "*.c" -or -name "*.cc" -or -name "*.cpp"`