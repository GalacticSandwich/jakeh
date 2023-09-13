
all: jakeh

jakeh: jakeh.o lang.o
	gcc -Wall -std=c99 jakeh.o lang.o -o jakeh

jakeh.o: jakeh.c lang.h
	gcc -Wall -std=c99 -g jakeh.c -c

lang.o: lang.c lang.h
	gcc -Wall -std=c99 -g lang.c -c

clean:
	rm -f *.o
