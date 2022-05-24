//  g++ ./dr14/main.cpp -o ./dr14/main && ./dr14/main
#include <stdlib.h>
#include <iostream>
using namespace std;
class B1{
    public:

    B1(){}
    void f(){
        cout<<"B1::f\n";
    }
    virtual void vf(){
        cout<<"B1::vf\n";
    }
    virtual void pvf(){
        cout<<"B1::pvf\n";
    }
};

class D1 : public B1{
    public:

    D1(){}
    void vf() override{
        cout<<"D1::vf\n";
    }
    void f(){ cout<<"D1:f\n"; }
};

class D2 : public D1 {
    public:

    D2(){};
    void pvf() override {
        cout<<"D2:pvf\n";
    }
};

class B2 : public B1 {
    public:

    B2(){};
    virtual void pvf(){
        cout<<"B2::pvf()\n";
    }

};

class D21 : public B2{
    public:
    
    string datamember;
    D21(){
        datamember = "something";
    };
    void pvf() override {
        cout<<datamember<<"\n";
    }
};

class D22 : public B2{
    public:
    
    int datamember;
    D22(){
        datamember = 11;
    };
    // void f(B2& ref){
    //     ref.pvf();
    // }
    void f(B2* p){ //Pointerre alakitas
        p->pvf();
    }
};
int main(){
    cout<<"objectB1---------\n";
    B1 objectB1;
    objectB1.f();
    objectB1.vf();
    objectB1.pvf();
    cout<<"objectD1---------\n";
    D1 objectD1;
    objectD1.f();
    objectD1.vf();
    objectD1.pvf();
    cout<<"ref--------------\n";
    B1& ref = objectD1;
    ref.f();
    ref.vf();
    ref.pvf();
    cout<<"objectD2---------\n";
    D2 objectD2;
    objectD2.f();
    objectD2.vf();
    objectD2.pvf();
    cout<<"objectD21---------\n";
    D21 objectD21;
    objectD21.f();
    objectD21.vf();
    objectD21.pvf();
    cout<<"objectD22---------\n";
    B2 objectB2;
    D22 objectD22;
    objectD22.f(&objectB2); // pointert megadni 
    objectD22.vf();
    objectD22.pvf();
    return 0;
}