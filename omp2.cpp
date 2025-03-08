#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define CHUNKSIZE   100
#define N       1000

int main (int argc, char *argv[]) 
{
int nthreads, tid;
int count = 0;
float a[N], b[N], c[N];


for (int i=0; i < N; i++)
  a[i] = b[i] = i * 1.0;


#pragma omp parallel shared(a,b,c) private(tid) firstprivate(count)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  printf("Thread %d starting...\n",tid);

  #pragma omp for schedule(dynamic,CHUNKSIZE)
  for (int i=0; i<N; i++)
    {
    c[i] = a[i] + b[i];
    printf("Thread %d: c[%d]= %f\n",tid,i,c[i]);
    count++;

    }
    printf("Thread %d done with count %d\n",tid,count);

  }  /* end of parallel section */
  printf("Count value outside parallel section %d\n",count);

}