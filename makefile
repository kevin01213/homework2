all:main.c type.o
	gcc main.c type.o -o  ./a.out
type.o:type.h type.c
	gcc -c type.c -o type.o
clean:
	rm main type.o



