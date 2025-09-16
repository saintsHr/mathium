src := $(shell find src -name '*.c')
include = -Iinclude

all:
	gcc -c -O0 -Wall -Wextra -fsanitize=address -fsanitize=undefined $(src) $(include)
	mkdir -p build
	mkdir -p lib
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o

dis:
	gcc -c -O3 -Ofast -mtune=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer $(src) $(include)
	mkdir -p build
	mkdir -p lib
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o

clean:
	rm -rf build/*.o
	rm -rf lib/*.a