CC=gcc

sources = $(wildcard *.c)
binaries = $(basename $(sources))
binaries32 = $(addsuffix _32, $(binaries))

all: $(binaries) $(binaries32)

$(binaries):
	gcc $@.c -o $@

$(binaries32):
	gcc $(subst _32,,$@).c -m32 -o $@

.PHONY : clean
clean:
	rm $(binaries) $(binaries32)
