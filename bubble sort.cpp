#include <iostream>
using namespace std;

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

void bubbleSort(int* a,int n){
    int temp;
    for (int i = 0; i < n-1; i++)//For number of passes
    {
        for (int j = 0; j < n-1-i; j++)//For comparison between elements
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
        
    }
    
}

void bubbleSortAdaptive(int* a,int n){
    int temp;
    int sorted=0;
    for (int i = 0; i < n-1; i++)//For number of passes
    {
        cout<<"Pass number: "<<i+1<<endl;
        sorted=1;
        for (int j = 0; j < n-1-i; j++)//For comparison between elements
        {
            if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            sorted=0;
            }
        }
        if (sorted)
        {       
            return;
        }
    } 
}

int main()
{
    int a[]={23,54,67,25,7,4};
    // int a[]={1,2,3,4,5,6};int a[]={1,2,3,4,5,6};
    int size=6;

    display(a,size);
    cout<<"After sorting "<<endl;
    bubbleSortAdaptive(a,size);
    display(a,size);
    
    return 0;
}