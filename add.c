#include <stdio.h>
#include <omp.h>
#include<time.h>
#include<math.h> 
#include<stdlib.h>

int main(void)
{
	int size=1;
	int i;
	float arr1[100000];
	float arr2[100000];
	float p[100000];
	float s[100000];
	double start = omp_get_wtime(); 

	#pragma omp parallel for
	for (i = 0; i < 100000; i++) 
	{
		arr1[i]=rand()*100;
		arr2[i]=rand()*100; 
	}
	double end = omp_get_wtime(); 
	double elapsed=end-start;        
	printf("Made The two arrays in %f\n",elapsed);

	start = omp_get_wtime();     
	#pragma omp parallel for
	for (i = 0; i < 100000; i++) 
	{
		p[i]=arr1[i]+arr2[i];
	}
	end = omp_get_wtime(); 
	elapsed=end-start;        
	printf("Added PARALLEL in %f \n",elapsed);

	start = omp_get_wtime();     
	for (i = 0; i < 100000; i++) 
	{
		s[i]=arr1[i]+arr2[i];
	}
	end = omp_get_wtime(); 
	elapsed=end-start;        
    printf("Added SERIAL in %f \n",elapsed);
    
  return 0;
}
