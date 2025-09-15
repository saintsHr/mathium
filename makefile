src = src/*.c
include = -Iinclude

all:
	gcc -c -O3 -Ofast -march=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathplus.a build/*.o

clean:
	rm -rf build/*.o
	rm -rf lib/*.a