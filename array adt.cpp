#include <iostream>
using namespace std;


class array{

    public:
    int totalsize;
    int usedsize;
    int* ptr;

    void createarray(array* a,int tsize,int usize){
        a->totalsize=tsize;
        a->usedsize=usize;
        a->ptr=new int[tsize];        
    }

    void setval(array* a){
        int n;
        for(int i=0;i<a->usedsize;i++){
            cout<<"Enter the element: "<<endl;
            cin>>n;
            a->ptr[i]=n;
        }
    }
    
    void display(){
        for(int i=0;i<a->usedsize;i++){
            
            cout<<" "<<a->ptr[i];
        }
    }
};

int main()
{
    array ajinkya;
    ajinkya.createarray(ajinkya,5,3);
    ajinkya.setval(ajinkya);
    ajinkya.display();


    return 0;
}