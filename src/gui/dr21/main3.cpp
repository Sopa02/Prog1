#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
template<typename T>
void readFromFile(std::string filename, T& v){
    std::ifstream ins {filename};
    for (double i; ins>>i;)
    {
        v.push_back(i);
    }
}

template<typename T, typename Z>
Z sum(T& v, Z ini)
{
    for(const auto& x : v){
        ini += x;
    }
    return ini;
}

int main(){

    std::vector<double> vd;
    readFromFile("file2.txt",vd);
    for(const auto& x:vd){
        std::cout<<x<<'\n';
    }
    std::vector<int> vi(21);
    std::copy(vd.begin(),vd.end(),vi.begin());

    for (int i = 0; i < 21; i++)
    {
        std::cout<<vd[i]<<" - "<<vi[i]<<'\n';
    }
    double sumvd = sum(vd,0.0);
    double sumvi = sum(vi,0);
    std::cout<<"vd sum: "<<sumvd<<'\n';
    std::cout<<"vd_sum-vi_sum= "<<sumvd-sumvi<<'\n';

    std::reverse(vd.begin(),vd.end());
    for(const auto& x:vd){
        std::cout<<x<<'\n';
    }

    return 0;
}