#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

template<typename Iter1, typename Iter2, typename p> 
Iter2 mycopy_if(Iter1 f1, Iter1 e1, Iter2 f2, p pred){
    if (f1==e1)
    {
        return f2;
    }
    Iter1 it;
    for(it = f1; it!=e1; ++it){
            if(pred(*it))
                *++f2 = *it;
    }
    return f2;
}

struct Less_than
{
    double val;
    public:
        Less_than(double x){val=x;}
        bool operator()(const double& a) const {return a<val;}
};

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

    std::cout<<"Mean of vd: "<<sum(vd,0.0)/vd.size()<<'\n';

    std::vector<double> vd2(21);
    mycopy_if(vd.begin(),vd.end(),vd2.begin(),Less_than(sum(vd,0.0)/vd.size()));

    std::cout<<"vd2: "<<'\n';
    for (const auto& x : vd2)
    {
        std::cout<<x<<'\n';
    }
    

    return 0;
}