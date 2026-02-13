DEBUG = -O0 -g #-fsanitize=address
RELEASE = -O3
MODE = $(DEBUG)

build: vtex.c
	mkdir -p build lib
	cc -c vtex.c -o build/vtex.o $(MODE)
	ar rcs lib/libvtex.a build/vtex.o

test: test.c build
	cc test.c -o build/test -L./lib -lvtex $(MODE)
	build/test
