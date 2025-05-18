#include <iostream>
using namespace std;

class calculator{
    public:
    int a;
    int b;

};

class addition: public calculator{
    public:
    
    void add(int c,int d){
        a=c;
        b=d;
       
        cout<<"Addition of the numbers is "<<a+b<<endl;
    }
};

class subtraction: public calculator{
    public:
    
    
    void sub(int o,int p){
        a=o;
        b=p;

        cout<<"Subtraction of the numbers is "<<a-b<<endl;
    }
};
class multiplication: public calculator{
    public:
    
    
    void mul(int k,int l){
        a=k;
        b=l;

        cout<<"Multiplication of the numbers is "<<a*b<<endl;
    }
};
class division: public calculator{
    public:
    
    void div(int x,int y){
        a=x;
        b=y;

        cout<<"Division of the numbers is "<<a/b<<endl;
    }
};

int main()
{

   int u,v;

   cout<<"Enter the numbers with which you want to perfor operations: "<<endl;
   cin>>u>>v;

   cout<<"1.Perform addition "<<endl;
   cout<<"2.Perform subtraction "<<endl;
   cout<<"3.Perform multiplication "<<endl;
   cout<<"4.Perform division "<<endl;
   cout<<"5.Exit the program "<<endl;

   cout<<"Enter the choice number is "<<endl;
   int ch;
   cin>>ch;

   switch (ch){
case 1:
    addition adda;
    adda.add(u,v);
    break;

case 2:
    subtraction suba;
    suba.sub(u,v);
    break;

case 3:
    multiplication mula;
    mula.mul(u,v);
    break;

case 4:
    division diva;
    diva.div(u,v);
    break;

case 5:
    cout<<"Exiting the program...."<<endl;
    break;

   
    
   }
    

    
    

    
    
    
    return 0;
}