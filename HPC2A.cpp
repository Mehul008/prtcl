#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);


void bubble(int *a, int n)
{
    for(  int i = 0;  i < n;  i++ )
     {  	 
   	 int first = i % 2; 	 

   	 #pragma omp parallel for shared(a,first)
   	 for(  int j = first;  j < n-1;  j += 2  )
   	   {  	 
   		 if(  a[ j ]  >  a[ j+1 ]  )
   		  {  	 
     			 swap(  a[ j ],  a[ j+1 ]  );
   		  }  	 
   	   }  	 
     }
}


void swap(int &a, int &b)
{

    int test;
    test=a;
    a=b;
    b=test;

}

int main()
{

    int *a,n;
    cout<<"\n enter total no of elements=>";
    cin>>n;
    a=new int[n];
    cout<<"\n enter elements=>";
    for(int i=0;i<n;i++)
    {
   	 cin>>a[i];
    }
    
    bubble(a,n);
    
    cout<<"\n sorted array is=>";
    for(int i=0;i<n;i++)
    {
   	 cout<<a[i]<<"\t";
    }


return 0;
}
//-----------------------------------------------------OUTPUT-------------------------------------------------------------
/*
gescoe@gescoe-OptiPlex-3010:~/Aniket$ g++ -o gfg -fopenmp HPC2A.cpp
gescoe@gescoe-OptiPlex-3010:~/Aniket$ ./gfg

 enter total no of elements=>20

 enter elements=>12
34
56
78
90
75
63
87
13
16
24
27
39
71
00
99
102
1055
23
56

 sorted array is=>0	12	13	16	23	24	27	34	39	56	56	63	71	75	78	87	90	99	102	1055	
gescoe@gescoe-OptiPlex-3010:~/Aniket$ 
*/
