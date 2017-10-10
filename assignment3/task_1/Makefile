 OPT = -O1 				

default: cachetest1 cachetest2

cachetest1: cachetest1.c 
	gcc $(OPT) cachetest1.c -o cachetest1

cachetest2: cachetest2.c
	gcc $(OPT) cachetest2.c -o cachetest2

run: default
	runhaskell generateLatexTable.hs

clean:
	rm -f *.o
	rm -f cachetest1
	rm -f cachetest2
	
