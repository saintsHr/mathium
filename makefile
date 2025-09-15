src = src/number-theory/*.c
include = -Iinclude

all:
	gcc -c $(src) $(include)
	mv *.o build/
	ar rcs lib/libmathplus.a build/*.o

clean:
	rm -rf build/*.o
	rm -rf lib/*.a