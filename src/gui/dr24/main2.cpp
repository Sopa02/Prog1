#include <iostream>
#include <string>
#include <math.h>
#include "./include/Matrix.h"
#include <complex>

using namespace Numeric_lib;

int main(){

    std::cout<<"Give me some int, I'll give you the square root of them. Quit with \'q\'\n";
    std::string str="";
    while(std::cin>>str){
        if(str=="q"){
            std::cout<<"Quit\n";
            break;
        }
        int x;
        try
        {
            x = std::stoi(str);
        }
        catch(const std::exception& e)
        {
            std::cout<<"That was no int, sir. Quit\n";
            break;
        }
        
        if (x<0)
        {
            std::cout<<"Illegal number - no square root\n";
        }else
            std::cout<<"Square root of "<<x<<'='<<sqrt(x)<<'\n';
        
        str = "";
    }
    Matrix<double> mx(10);
    std::cout<<"Give me 10 double values, I'll put them in a Matrix.\n";

    for (int i = 0; i < 10; i++)
    {
        std::string str = "";
        std::cin>>str;
        double d;
        try
        {
            d = std::stod(str);  
        }
        catch(const std::exception& e)
        {
            std::cout<<"That aint no double sir. Try again next time\n";
            break;
        }
        mx[i] = d;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout<<"mx matrix element #"<<i<<'='<<mx[i]<<'\n';
    }
    
    std::cout<<"Give an \'m\' and an \'n\' number, and I'll make a multiplication table of [0,n)*[0,m)";
    int m;
    int n;
    std::cin>>m;
    std::cin>>n;
    std::cout<<"------------------\n";
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            std::cout<<i*j<<'\t';
        }
        std::cout<<'\n';
        
    }
    Matrix<std::complex<double>> compmx(10);
    std::complex<double> sum=0;
    for (int i = 0; i < 10; i++)
    {
        std::complex<double> x;
        std::cin>>x;
        compmx[i] = x;
        sum += x;
    }
    std::cout<<sum<<'\n';
    


    return 0;
}