CC=g++
CPPFLAGS=-std=c++17 -O2 -Iinclude -Wall
SRC=src/ezd.o src/node.o src/arith.o
TEST=test/main.o test/test_arith.o test/test_reg.o

ezd.a: include/* $(SRC)
	ar rs ezd.a $(SRC)

test.out: ezd.a $(TEST)
	$(CC) $(CPPFLAGS) -lgtest ezd.a $(TEST) -o test.out

test: test.out
	./test.out

install: ezd.a
	mkdir -p /usr/local/include/ezd
	cp -r include/* /usr/local/include/ezd
	cp ezd.a /usr/local/lib

uninstall:
	rm -rf /usr/local/include/ezd
	rm -rf /usr/local/lib/ezd.a

docs:
	doxygen

clean:
	rm -rf ezd.a
	rm -rf test.out
	rm -rf $(SRC)
	rm -rf $(TEST)
	rm -rf docs

