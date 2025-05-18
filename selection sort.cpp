#include <iostream>
using namespace std;

void display(int* a,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

void selectionSort(int* a,int n){
    int key,temp;
    for (int i = 0; i < n-1; i++)
    {
        key=a[i];
        
        
        for (int j=i+1; j<n; j++)
        {
            if(a[j]<key){
               temp=a[j];
               a[j]=key;
               key=temp;
            }  
        }
        a[i]=key;
          
    } 
}

int main()
{
    int a[]={23,54,67,25,7,4};
    int size=6;

    display(a,size);

    selectionSort(a,size);
    cout<<"After sorting: "<<endl;
    display(a,size);

    
    return 0;
}