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

void freeArr(double **a, int size){
	for (int i = 0; i < size; i++){
		free(a[i]);
	}
	free(a);
}

int main (int argc, char *argv[])
{
	double t1, t2; 

	unsigned int REPEATS = 1000; 
	unsigned int N = 1000; 

	/* declare variables; examples, adjust for task */
	double **a = malloc(N * sizeof(double));
	double **b = malloc(N * sizeof(double));
	double **c = malloc(N * sizeof(double));
	for (int i = 0; i < N; i++){ // N*N
		a[i] = (double *)malloc(N * sizeof(double)); 
		b[i] = (double *)malloc(N * sizeof(double));	
		c[i] = (double *)malloc(N * sizeof(double));
	}

	/* initialise arrray elements */
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			a[i][j] = 1;
			b[i][j] = 1;
			c[i][j] = 0;
		}
	}

	t1 = getTime();
	/* code to be measured goes here */
	/***************************************/
	double **temp = malloc(N * sizeof(double)); // temp matrix, tranpose of b
	for (int i = 0; i < N; i++){
		temp[i] = (double *)malloc(N * sizeof(double));
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			temp[i][j] = b[j][i];
		}
	}	

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				c[i][j] += a[i][k] * temp[j][k]; // already tranposed 
			}
		}
	}

	/***************************************/
	t2 = getTime(); 

	/* output; examples, adjust for task */
	printf("matrix2 - time: %6.2f secs\n",(t2 - t1));

	/* IMPORTANT: also print the result of the code, e.g. the sum, 
	 * otherwise compiler might optimise away the code */
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			fprintf(stderr, "c[%d][%d]= %lf \n", i, j, c[i][j]);
		}
	}
	freeArr(a, N);
	freeArr(b, N);
	freeArr(c, N);

	return 0;  
}

