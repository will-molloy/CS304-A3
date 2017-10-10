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
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  unsigned int M = 1000;
  unsigned int N = 256*1024; 
  unsigned int i, r, j;
  unsigned int size = 1000;
	
  /* declare variables; examples, adjust for task */
	//int *a;
	// represents 2D arrays
	double *a;
	double *b;
 
  
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

    
  /* allocate memory for arrays; examples, adjust for task */
	 a = malloc (N * sizeof(double));
	 b = malloc (N * sizeof(double));

	 /* initialise arrray elements */
    for (int i = 0; i < N; i++){
        a[i] = i;
        b[i] = i;
    }
	 
  t1 = getTime();
  double c[1000];
  /* code to be measured goes here */
  /***************************************/
    for (r = 0; r < M; r++){ // Repeats
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
  //free(a);

  return 0;  
}
