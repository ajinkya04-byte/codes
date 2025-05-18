#include <iostream>
using namespace std;

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

void merge(int* a,int low,int mid,int high){
    
    int i=low,j=mid+1;
    int b[10];
    int k=low;
    while (i<=mid && j<=high)
    {
        if (a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }   
    }
    while (i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    
    while (j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for (int l = low; l <= high; l++) {
        a[l] = b[l];
    }
    
}

void mergeSort(int* a,int low,int high){
    
    if(low<high){
    int mid=(low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high); 
    }
}

int main()
{
    int a[]={23,54,67,25,7,4};
    int size=6;

    display(a,size);

    mergeSort(a,0,size-1);
    cout<<"After sorting: "<<endl;
    display(a,size);
    
    return 0;
}