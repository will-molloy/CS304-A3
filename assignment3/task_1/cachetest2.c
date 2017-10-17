/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
	struct timespec t;
	
	clock_gettime(CLOCK_MONOTONIC, &t);
	
	return t.tv_sec + 1.0e-9*t.tv_nsec;
}

/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
	double t1, t2; 

	/* variables for task 1 */
	unsigned int M;
	unsigned int N; 
	unsigned int i;

	/* declare variables; examples, adjust for task */
	int *a;

	/* parameter parsing task 1 */
	for(i=1; i<(unsigned)argc; i++) {
		if (strcmp(argv[i], "--repetitions") == 0) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &M);
			else
				usage();
		} else if (strcmp(argv[i], "--array_size") == 0) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &N);
			else
				usage();
		} else usage();
	}
	if (M < 1 || N < 1)
		usage();


	/* allocate memory for arrays; examples, adjust for task */
	a = malloc (N * sizeof(int));
	int *b;
	b = malloc (N * sizeof(int)); // helper array

	/* initialise arrray elements */
	for (int i = 0; i < N; i++){
		a[i] = 1;
		b[i] = i;
	}  
	/* case2: Shuffle b */
	for (int n = 0; n < N; n++) {
		int i = n + rand() / (RAND_MAX / (N - n) + 1);
		int temp = b[i];
		b[i] = b[n];
		b[n] = temp;
	}

	t1 = getTime();
	/* code to be measured goes here */
	/***************************************/
	unsigned int sum = 0;
	for (int m = 0; m < M; m++){ // M repeats
		for (int n = 0; n < N; n++){
			sum += a[b[n]];
		}    
	}
	/***************************************/
	t2 = getTime(); 

	/* output; examples, adjust for task */
	printf("%6.9f \n", (t2 - t1)/(M*N)); // nano seconds

	/* IMPORTANT: also print the result of the code, e.g. the sum, 
	 * otherwise compiler might optimise away the code */
	fprintf(stderr, "sum: %d\n", sum); 
	/* free memory; examples, adjust for task */
	free(a);
	free(b);

	return 0;  
}
