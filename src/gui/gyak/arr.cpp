#include <iostream>

template<typename T, int N>
struct arr{
    T elem[N];

    int size() const {return N;}
    T& operator[](int i){return elem[i];}
    const T& operator[](int i)const {return elem[i];}

    T* begin(){return &elem[0];}
    T* end(){return &elem[N];}

};

template<typename T>
void printout(T arg,std::string message){
    std::cout<<message<<'\n';
    for (auto& i : arg)
    {
        std::cout<<i<<' ';
    }
    std::cout<<'\n';
}

int main(){

    arr<int, 10> my_array{0,1,2,3,4,5,6,7,8,9};

    std::cout<<"For auto&\n";
    for (auto& i : my_array)
    {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl<<"For .size()\n";
    for (int i = 0; i < my_array.size(); i++)
    {
        std::cout<<my_array[i]<<' ';
    }
    std::cout<<'\n';
    
    arr<int, 10>arr2{9,8,7,6,5,4,3,2,1};
    arr<int,10>arr_empty;
    printout(arr2,"arr2");
    printout(arr_empty,"arr_empty");
    arr_empty = arr2;

    printout(arr_empty,"arr_empty after =");

    return 0;
}