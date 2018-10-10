#include<iostream>
#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
 
int a1[100000],a2[100000];
double time_seq1, time_seq2;

void oddEvenSort_seq()
{
    
    bool isSorted = false; 
    int i;
    double start_time = omp_get_wtime();
    while (!isSorted)
    {
        isSorted = true; 
        for (i=1; i<=100000-2; i=i+2)       
        {
            if (a1[i] > a1[i+1])
             {
                swap(a1[i], a1[i+1]);
                isSorted = false;
              }
        }
        for (i=0; i<=100000-2; i=i+2)           
        {
            if (a1[i] > a1[i+1])
            {
                swap(a1[i], a1[i+1]);
                isSorted = false;
            }
        }
    }
    time_seq2 = omp_get_wtime() - start_time;
    cout<<"\nSequential : \n";
    cout<<"10000: "<<time_seq2<<endl;
}
void oddEvenSort_para()
{
    bool isSorted = false; 
    int i;
    double start_time = omp_get_wtime();
    while (!isSorted)
    {
        isSorted = true; 
        #pragma omp parallel for private(i) shared(a2)
        for (i=1; i<=100000-2; i=i+2)       
        {
            if (a2[i] > a2[i+1])
             {
                swap(a2[i], a2[i+1]);
                isSorted = false;
              }
        }
        #pragma omp parallel for private(i) shared(a2)
        for (i=0; i<=100000-2; i=i+2)           
        {
            if (a2[i] > a2[i+1])
            {
                swap(a2[i], a2[i+1]);
                isSorted = false;
            }
        }
    }
    time_seq1 = omp_get_wtime() - start_time;
    cout<<"\nParallel : \n";
    cout<<"10000: "<<time_seq1<<endl;
}


int main()
{
    for(int i=0;i<100000;i++) {
        a1[i] = rand()%100000;
        a2[i] = a1[i];
    }
 oddEvenSort_seq();
 oddEvenSort_para();
  
    return (0);
}
