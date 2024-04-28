#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;


void mergesort(int a[],int i,int j);
void merge(int a[],int i1,int j1,int i2,int j2);

void mergesort(int a[],int i,int j)
{
	int mid;
	if(i<j)
	{
    	mid=(i+j)/2;
   	 
    	#pragma omp parallel sections
    	{

        	#pragma omp section
        	{
            	mergesort(a,i,mid);   	 
        	}

        	#pragma omp section
        	{
            	mergesort(a,mid+1,j);    
        	}
    	}

    	merge(a,i,mid,mid+1,j);    
	}

}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
	int temp[1000];    
	int i,j,k;
	i=i1;    
	j=i2;    
	k=0;
    
	while(i<=j1 && j<=j2)    
	{
    	if(a[i]<a[j])
    	{
        	temp[k++]=a[i++];
    	}
    	else
    	{
        	temp[k++]=a[j++];
    }    
	}
    
	while(i<=j1)    
	{
    	temp[k++]=a[i++];
	}
   	 
	while(j<=j2)    
	{
    	temp[k++]=a[j++];
	}
   	 
	for(i=i1,j=0;i<=j2;i++,j++)
	{
    	a[i]=temp[j];
	}    
}


int main()
{
	int *a,n,i;
	cout<<"\n enter total no of elements=>";
	cin>>n;
	a= new int[n];

	cout<<"\n enter elements=>";
	for(i=0;i<n;i++)
	{
    	cin>>a[i];
	}
	mergesort(a, 0, n-1);
	
	cout<<"\n sorted array is=>";
	for(i=0;i<n;i++)
	{
    	cout<<a[i]<<" ";
	}
	return 0;
}

//------------------------------------------------OUTPUT--------------------------------------------------------

/*
gescoe@gescoe-OptiPlex-3010:~/Aniket$ g++ -o gfg -fopenmp HPC2B.cpp
gescoe@gescoe-OptiPlex-3010:~/Aniket$./gfg

 enter total no of elements=>25

 enter elements=>1
4
3
2
6
5
9
8
7
12
23
23
21
54
34
76
67
65
123
234
432
321
543
765
876

sorted array is=>1 2 3 4 5 6 7 8 9 12 21 23 23 34 54 65 67 76 123 234 321 432 543 765 876 
gescoe@gescoe-OptiPlex-3010:~/Aniket$ 

*/
