#include <iostream>
#include <limits.h>
using namespace std;


void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

int maximum(int a[],int n){
    int max=INT_MIN;
    for (int i = 0; i <= n-1; i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
        
    }
    return max;
}

void countSort(int* a,int n){
    int max=maximum(a,n);
    int i,j;
    int* count=new int(max+1);
    
    for (i = 0; i < max+1; i++)
    {
        count[i]=0;
    }

    for (i = 0; i < n; i++)
    {
        count[a[i]]=count[a[i]]+1;
    }
    
    i=0; //count array
    j=0; //given array

    while (i<=max)
    {
        if(count[i]>0){
            a[j]=i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
        
    }
    
}

int main()
{
    int a[]={23,54,67,25,7,4};
    int size=6;

    display(a,size);

    countSort(a,size);
    cout<<"After sorting: "<<endl;
    display(a,size);
    
    

    return 0;
}