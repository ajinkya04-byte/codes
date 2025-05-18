#include <iostream>
using namespace std;


int linear_search(int arr[],int element,int size){

    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }  
    
    }
    return -1;
}

int binary_search(int arr[],int element,int size){

    int low=0;
    int mid,high=size-1;

    while(low<=high){
    mid=(low+high)/2;

        if(arr[mid]==element){
            return mid;
            cout<<"Binary search used "<<endl;
        }

        if(arr[mid]<element){
            low=mid+1;
            cout<<"Searching in the list greater than mid "<<endl;
        }

        else{
            high=mid-1;
           cout<<"Searching in the list lesser than list "<<endl;
        }
    }
    return 2;
   
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
        
    }
}

int main()
{   
    int size=9;
    int capacity=15;
    int arr[capacity]={2,4,8,16,32,64,128,256,512};
    display(arr,size);
    int element=64;

    // int search=linear_search(arr, element, size);
    // cout<<"Element found at index "<<search<<endl;

    int search=binary_search(arr, element,size);
    cout<<"--->"<<element<<"<--- @ "<<search<<endl;


    return 0;
}