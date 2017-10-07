#include <stdio.h>
#include <stdlib.h>

#include "zeitmessung.h"

#define N 3200
#define MAX_SIZE N*N
#define REPEATS 200


int main (int argc, char *argv[])
{

  int *a;
  int i, j, r; 
  long sum = 0;
  double t1, t2;

    
  a = malloc (MAX_SIZE * sizeof (int));
	  
  for (j = 0; j < N; j++){
    for (i = 0; i < N; i++){
      a[j*N+i] = j*N+i;
    }
  }

  t1 = getTime(); 
  for (r = 0; r < REPEATS; r++){
    for (i = 0; i < N; i+=1){
      for (j = 0; j < N; j+=1){
       sum += a[j*N + i]*11;
      }
    }
  }  
  t2 = getTime();

  printf("time: %6.2f secs, result: %d \n",t2 - t1, sum);

}
