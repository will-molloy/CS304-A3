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
  
  /* variables for task 1 */
  unsigned int M = 1000;
  unsigned int N = 256*1024; 
  unsigned int i;
	
  /* declare variables; examples, adjust for task */
	int *a; // task1
	//double  a[100]; // task2
 
  
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
	a = malloc (N * sizeof(int));
    int *b;
    b = malloc (N * sizeof(int)); // helper array - case 1: not shuffled.
    
	 /* initialise arrray elements */
   for (int i = 0; i < N; i++){
        a[i] = 1;
        b[i] = i;
   }  
    /* case1: b remains linear */
	 
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
    unsigned int sum = 0;
    for (int m = 0; m < M; m++){
        for (int n = 0; n < N; n++){
              sum += a[b[n]];
        }    
    }
  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("%6.10f \n",(t2 - t1)/M);

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
 fprintf(stderr, "sum: %d\n", sum/M); 
  /* free memory; examples, adjust for task */
  //free(a);

  return 0;  
}
