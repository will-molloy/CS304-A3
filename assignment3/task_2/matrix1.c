/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
	struct timeval t;
	double sec, msec;

	while (gettimeofday(&t, NULL) != 0);
	sec = t.tv_sec;
	msec = t.tv_usec;

	sec = sec + msec/1000000.0;

	return sec;
}

int main (int argc, char *argv[])
{
	double t1, t2; 

	unsigned int M = 1000;
	unsigned int N = 256*1024; 
	unsigned int i, r, j;
	unsigned int size = 1000;

	/* declare variables; examples, adjust for task */
	// represents 2D arrays
	double *a; // src1
	double *b; // src2
	double *c; // result 

	/* allocate memory for arrays; examples, adjust for task */
	a = malloc (N*N * sizeof(double));
	b = malloc (N*N * sizeof(double));
	c = malloc (N*N * sizeof(double));
	/* initialise arrray elements */
	for (int i = 0; i < N*N; i++){
		a[i] = 1;
		b[i] = 1;
	}

	t1 = getTime();
	/* code to be measured goes here */
	/***************************************/
	for (r = 0; r < M; r++){ // M, Repeats
		for (i = 0; i < size; i++){
			for (j = 0; j < size; j++){
				c[j*size + i] = a[j*size + i] *  b[j + i*size];
			}
		}
	}  
	/***************************************/
	t2 = getTime(); 

	/* output; examples, adjust for task */
	printf("time: %6.2f secs\n",(t2 - t1));

	/* IMPORTANT: also print the result of the code, e.g. the sum, 
	 * otherwise compiler might optimise away the code */
	for (i = 0; i < size*size; i++){
		printf("c[%d]: %d", i, c[i]);
	}

	/* free memory; examples, adjust for task */
	free(a);
	free(b);
	free(c);

	return 0;  
}
