#include <iostream>
#include <string>
#include <vector>
#include "./include/Matrix.h"

using namespace Numeric_lib;

template<typename T> 
void printSize(T var,std::string str){
    std::cout<<"Size of a "<<str<<":  \t"<<sizeof(var)<<"byte(s).\n";
}

template<typename T> 
void printNumOfElem(T var,std::string str){
    std::cout<<"Number of elements of "<<str<<":      \t"<<var.size()<<".\n";
}


int main(){

    char ch;
    short s;
    int i;
    long l;
    float f;
    double dou;
    int* i_p;
    double* d_p;

    printSize(ch,"char");
    printSize(s,"short");
    printSize(i,"int");
    printSize(l,"long");
    printSize(f,"float");
    printSize(dou,"double");
    printSize(i_p,"int*");
    printSize(d_p,"double*");
    
    std::cout<<"-------------\n\n";

    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

    printSize(a,"a(10) - int");
    printSize(b,"b(100) - int");
    printSize(c,"c(10) - double");
    printSize(d,"d(10,10) - int");
    printSize(e,"e(10,10,10) - int");

    std::cout<<"-------------\n\n";

    printNumOfElem(a,"a(10) - int");
    printNumOfElem(b,"b(100) - int");
    printNumOfElem(c,"c(10) - double");
    printNumOfElem(d,"d(10,10) - int");
    printNumOfElem(e,"e(10,10,10) - int");
    
    

    return 0;
}