LIB_INSTALL=$(HOME)/lib
INCLUDE_INSTALL=$(HOME)/include

CURDIR=/opt/local/lib -L.
TEST_LIBS=-L$(CURDIR) -lcunit

CPPFLAGS=-DDEBUG -I/opt/local/include -I./src
CFLAGS=-Wall -std=c99
CXXFLAGS=-Wall -std=c++11

default: nethelper.o staticlib test

test: unit/test.cpp libcantcoap.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -o $@ -lcantcoap $(TEST_LIBS)

cantcoap.o: src/cantcoap.cpp src/cantcoap.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $< -c -o $@

nethelper.o: examples/common/nethelper.c examples/common/nethelper.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -c -o $@

staticlib: libcantcoap.a

libcantcoap.a: cantcoap.o
	$(AR) $(ARFLAGS) libcantcoap.a $^

clean:
	$(RM) *.o test libcantcoap.a

install:
	install libcantcoap.a $(LIB_INSTALL)/
	install ./src/cantcoap.h $(INCLUDE_INSTALL)/
