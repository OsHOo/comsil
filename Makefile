main.out: main.o recursive.o search.o
	gcc -o main.out main.o recursive.o search.o

main.o: define.h recursive.h main.c
	gcc -c -o main.o main.c

recursive.o: define.h recursive.h search.h recursive.c
	gcc -c -o recursive.o recursive.c

search.o : define.h search.h search.c
	gcc -c -o search.o search.c

clean:
	rm -f *.o
	
