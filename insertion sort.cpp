#include <iostream>
using namespace std;

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

void insertionSort(int* a,int n){
    int key,j;
    for (int i = 1; i < n; i++)
    {
        key=a[i];
        j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    
}

int main()
{
    int a[]={23,54,67,25,7,4};
    int size=6;

    display(a,size);

    insertionSort(a,size);
    cout<<"After sorting array: "<<endl;

    display(a,size);
    return 0;
}