all:main.c type.o
	gcc main.c type.o hash.o -o  ./a.out
type.o:type.h type.c
	gcc -c type.c -o type.o
hash.o:hash.h hash.c
	gcc -c hash.c -o hash.o
clean:
	rm main type.o hash.o



