#include <iostream>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
        
    }
}

int insertion_at_index(int arr[],int size,int capacity,int element,int index){

    if(size>=capacity){
        return -1;
    }
    for(int i=size-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;

    return 1;
}

int deletion_at_index(int arr[],int size,int capacity,int element,int index){

    if(size==0){
        return -1;
    }

    for(int i=index;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
    return 2;   
}


int main()
{   
    int capacity=10;
    int arr[capacity]={25,24,17,26,23};
    int size=5,element=54,index=3;

    
    size=size+1;
    insertion_at_index(arr,size,capacity,element,index);
    display(arr,size);
    cout<<"\n";
    size=size-1;
    deletion_at_index(arr,size,capacity,element,index=2);
    display(arr,size);
    
    return 0;
}