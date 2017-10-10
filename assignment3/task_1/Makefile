 OPT = -O1 				

default: cachetest1 cachetest2

cachetest1: cachetest1.o 
	gcc $(OPT) -o cachetest1 cachetest1.o

cachetest1.o: cachetest1.c
	gcc $(OPT) -c cachetest1.c

cachetest2: cachetest2.c
	gcc $(OPT) cachetest2.c -o cachetest2

run: default
	runhaskell gentable.hs

clean:
	rm -f *.o
	rm -f assignment

