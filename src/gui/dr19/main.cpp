#include <vector>
#include <string>
#include <iostream>




template<typename T> struct S {
    T val;
    public:
        S(T x){ val = x;};
        S(){val = T();};
        T& get();
        const T& get() const;
        void set(T x);
        S<T>::operator=(const T&);

};
template<typename T> T& S<T>::get(){return val;}
template<typename T> const T& S<T>::get() const {return val;}
template<typename T> void S<T>::set(T x) {val = x;}
template<typename T> void read_val(T& v){    
    std::cin >> v;
};



int main(){
    
    std::vector<int> asd;
    for (int i = 0; i < 10; i++)
    {
        asd.push_back(i);
    }
    


    S<int> s_int = 11;
    S<char> s_char = 'x' ;
    S<double> s_double = 32.2;
    std::string something = "ASD";
    S<std::string> s_string = something;
    S<std::vector<int>> s_vector = asd;

    std::cout<<s_int.get()<<'\n';
    std::cout<<s_char.get()<<'\n';
    std::cout<<s_double.get()<<'\n';
    std::cout<<s_string.get()<<'\n';
    for (int i = 0; i < 10; i++)
    {
        std::cout<<s_vector.get()[i]<<'\n';
    }

    // nem jo
    int example;
    read_val(example);
    s_int.set(example);

    // ez sem jo
    s_int = example;

    // ez sem
    read_val(s_int);
    
    std::cout<<s_int.get()<<'\n';

    return 0;
}