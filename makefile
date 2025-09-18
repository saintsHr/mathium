src := $(shell find src -name '*.c')
include = -Iinclude

flags = -c -O0 -Wall -Wextra -fsanitize=address -fsanitize=undefined
disflags = -c -O3 -Ofast -mtune=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer

all:
	mkdir -p build
	mkdir -p lib
	gcc $(flags) $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o

dis:
	mkdir -p build
	mkdir -p lib
	gcc $(disflags) $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathium.a build/*.o
