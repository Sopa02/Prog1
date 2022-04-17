#include <map>
#include <string>
#include <iostream>


int main(){

    std::map<std::string,int> msi;

    msi = {
        {"perec",20},
        {"kalács",30},
        {"kenyér",40},
        {"pita",50},
        {"kifli",60},
        {"zsemle",70},
        {"lepény",80},
        {"lángos",90},
        {"pizza",100},
        {"fánk",110}
    };

    for(const auto& x : msi){
        std::cout<<x.first<<"\t"<<x.second<<'\n';
    }
    msi = {};
    // for(const auto& x : msi){
    //     msi.erase(x.first);
    // }

    for(std::string s; std::cin>>s;){
        if (s=="q") break;
        ++msi[s];
    }
    for(const auto& x : msi){
        std::cout<<x.first<<"\t"<<x.second<<'\n';
    }

    int sum = 0;
    for(const auto& x : msi){
        sum+=x.second;
    }
    std::cout<<sum<<'\n';

    std::map<int,std::string> mis;

    for(const auto& x : msi){
        mis[x.second]=x.first;
    }

    for(const auto& x : mis){
        std::cout<<x.first<<"\t"<<x.second<<'\n';
    }

    return 0;    
}