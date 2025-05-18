#include <iostream>
using namespace std;

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

int partition(int a[],int low,int high){
    int pivot=a[low];
    int i=low+1;
    int j=high;
    int temp;

    do
    {
    
    
    while (a[i]<=pivot)
    {
        i++;
    }
    
    while (a[j]>pivot)
    {
       j--;
    }
    
    if(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    }
    while (i<j);

    temp=a[low];
    a[low]=a[j];
    a[j]=temp;

    return j;
    
}

void quickSort(int* a,int low,int high){
    int pivotIndex;

    if(low<high){
    pivotIndex=partition(a,low,high);
    quickSort(a,low,pivotIndex-1);
    quickSort(a,pivotIndex+1,high);
    }
}

int main()
{
    int a[]={23,54,67,25,7,4};
    int size=6;

    display(a,size);

    quickSort(a,0,size-1);
    cout<<"After sorting: "<<endl;
    display(a,size);
    
    return 0;
}