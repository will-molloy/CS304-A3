 OPT = -O3 				

default: cacheTest

cacheTest: cacheTest.o zeitmessung.o
	gcc $(OPT) -o cacheTest cacheTest.o zeitmessung.o

cacheTest.o: cacheTest.c
	gcc $(OPT) -c cacheTest.c

zeitmessung.o: zeitmessung.c
	gcc $(OPT) -c zeitmessung.c

clean:
	rm -f *.o
	rm -f cacheTest

