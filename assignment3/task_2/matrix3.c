/*
 ============================================================================
 Name        : matrix3.c
 Author      : Will Molloy, wmol664 
 Date        : October 2017
 Description : Matrix multiplication with blocking/tiling
 ============================================================================
 */

/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#define N 1000 
#define BLOCK_SIZE 64 // cache line size

double getTime(){
    struct timeval t;
    double sec, msec;

    while (gettimeofday(&t, NULL) != 0);
    sec = t.tv_sec;
    msec = t.tv_usec;

    sec = sec + msec/1000000.0;

    return sec;
}

void freeArr(double **a, int numRows){
    for (int i = 0; i < numRows; i++){
        free(a[i]);
    }
    free(a);
}

int min (int a, int b){
    if (a < b)
        return a;
    return b;
}

int main (int argc, char *argv[])
{
    double t1, t2; 

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
    for (int i = 0; i < N; i+=BLOCK_SIZE){
        for (int j = 0; j < N; j+=BLOCK_SIZE){
            for (int k = 0; k < N; k+=BLOCK_SIZE){
                // Blocking
                for (int ib = i; ib < min(i+BLOCK_SIZE, N); ib++){
                    for (int jb = j; jb < min(j+BLOCK_SIZE, N); jb++){
                        for (int kb = k; kb < min(k+BLOCK_SIZE, N); kb++){
                                c[ib][jb] += a[ib][kb] * b[kb][jb]; // No pre transpose
                        }
                    } 
                }

            }
        }
    }
    /***************************************/
    t2 = getTime(); 

    /* output; examples, adjust for task */
    printf("matrix3 - time: %6.2f secs\n",(t2 - t1));

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

