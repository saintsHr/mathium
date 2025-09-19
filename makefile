wc64 = x86_64-w64-mingw32-gcc
wc32 = i686-w64-mingw32-gcc
wl64 = x86_64-w64-mingw32-ar
wl32 = i686-w64-mingw32-ar

src := $(shell find src -name '*.c')
include = -Iinclude

flags = -c -O0 -Wall -Wextra -fsanitize=address -fsanitize=undefined
disflags = -c -O3 -Ofast -mtune=native -flto -funroll-loops -ftree-vectorize -fomit-frame-pointer -DNDEBUG

all:
	mkdir -p build
	mkdir -p lib

#============Linux 64 bits==============
	gcc $(flags) $(src) $(include)
	mv *.o build/
	ar rcs lib/linux/libmathium64.a build/*.o
#=======================================

	rm -rf build/*.o

#============Linux 32 bits==============
	gcc -m32 $(flags) $(src) $(include)
	mv *.o build/
	ar rcs lib/linux/libmathium32.a build/*.o
#=======================================

	rm -rf build/*.o

#============Windows 64 bits==============
	$(wc64) $(flags) $(src) $(include)
	mv *.o build/
	$(wl64) rcs lib/windows/libmathium64.lib build/*.o
#=========================================

	rm -rf build/*.o

#============Windows 32 bits==============
	$(wc32) $(flags) $(src) $(include)
	mv *.o build/
	$(wl32) rcs lib/windows/libmathium32.lib build/*.o
#=========================================

	rm -rf build/*.o


dis: 
	mkdir -p build
	mkdir -p lib

#============Linux 64 bits==============
	gcc $(disflags) $(src) $(include)
	mv *.o build/
	ar rcs lib/linux/libmathium64.a build/*.o
#=======================================

	rm -rf build/*.o

#============Linux 32 bits==============
	gcc -m32 $(disflags) $(src) $(include)
	mv *.o build/
	ar rcs lib/linux/libmathium32.a build/*.o
#=======================================

	rm -rf build/*.o

#============Windows 64 bits==============
	$(wc64) $(disflags) $(src) $(include)
	mv *.o build/
	$(wl64) rcs lib/windows/libmathium64.lib build/*.o
#=========================================

	rm -rf build/*.o

#============Windows 32 bits==============
	$(wc32) $(disflags) $(src) $(include)
	mv *.o build/
	$(wl32) rcs lib/windows/libmathium32.lib build/*.o
#=========================================

	rm -rf build/*.o