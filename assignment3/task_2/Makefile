OPT = -O1 				

default: matrix1 matrix2 matrix3

matrix1: matrix1.c 
	gcc $(OPT) matrix1.c -o matrix1

matrix2: matrix2.c 
	gcc $(OPT) matrix2.c -o matrix2

matrix3: matrix3.c 
	gcc $(OPT) matrix3.c -o matrix3


run: default
	./matrix1 2>/dev/null
	./matrix2 2>/dev/null
	./matrix3 2>/dev/null

clean:
	rm -f *.o
	rm -f matrix1
	rm -f matrix2
	rm -f matrix3
