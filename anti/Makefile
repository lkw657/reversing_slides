CC=gcc

binaries = 1 2 3 stripped static nostrings ptrace sigtrap instructions

all: $(binaries)

instructions:
	gcc $@.c -masm=intel -o $@

1 2 3 ptrace sigtrap:
	gcc $@.c -o $@

stripped:
	gcc -s -fvisibility=hidden 2.c -o $@

static:
	musl-gcc -static 2.c -o $@

staticStripped nostrings:
	musl-gcc -s -fvisibility=hidden -static 2.c -o $@

.PHONY : clean
clean:
	rm $(binaries)
