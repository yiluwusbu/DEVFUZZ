#
# makefile for aplib 
# 2019-2022 Tong Zhang<ztong0001@gmail.com>
# 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
#
CC=clang
CXX=clang++
LINK=clang++

UNAME_S := $(shell uname -s)

CFLAGS=-g -I../ -I./ -I./pci -I./usb -fPIC
CXXFLAGS=-g -std=c++14 -I../ -I./ -I./pci -I./usb -fPIC -std=c++14

LDFLAGS=-lpthread -std=c++14 -fPIC

ifeq ($(UNAME_S),Linux)
  LDFLAGS += -lrt
endif
ifeq ($(UNAME_S),Darwin)
  LDFLAGS += 
endif


aplib.so:
	$(CXX) hw_model.cpp $(CXXFLAGS) -c
	$(CXX) aplib.cpp $(CXXFLAGS) -c
	$(LINK) aplib.o hw_model.o -shared -o aplib.so $(LDFLAGS)

clean:
	rm -f aplib.so aplib.o hw_model.o test

test: aplib.so
	$(CXX) test.cpp $(CXXFLAGS) -c
	$(CXX) hw_model.cpp $(CXXFLAGS) -c
	$(CXX) test.o aplib.o hw_model.o $(LDFLAGS) -o test

indent:
	clang-format -i -style=file `find . -name '*.cpp' -or -name "*.h" -or -name "*.c" -or -name "*.cc"`

SCOPE_FILE = cscope.out
TAG_FILE   = tags

tags:
	rm -f ${SCOPE_FILE} scope.* ${TAG_FILE}
	find ${SRC_DIRS} -type f \
    -a \( -name "*.h" -o -name "*.hpp" -o -name "*.cpp" -o -name "*.c" \
    -o -name "*.cc" \) > ${SCOPE_FILE}
	ctags -I "__THROW __nonnull __attribute_pure__ __attribute__ G_GNUC_PRINTF+" \
		--file-scope=yes --c++-kinds=+px --c-kinds=+px --fields=+iaS -Ra --extra=+fq \
		--langmap=c:.c.h.pc.ec --languages=c,c++ --links=yes \
		-f ${TAG_FILE} -L ${SCOPE_FILE}
	cscope -Rb -i ${SCOPE_FILE}

.PHONY: aplib.so
