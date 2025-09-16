src := $(shell find src -name '*.c')
include = -Iinclude

all:
	mkdir -p build
	mkdir -p lib
	gcc -c -O0 -Wall -Wextra -fsanitize=address -fsanitize=undefined $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o

dis:
	mkdir -p build
	mkdir -p lib
	gcc -c -O3 -Ofast -mtune=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o