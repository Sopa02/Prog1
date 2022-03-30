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
        void operator=(const T& x);

};
template<typename T> T& S<T>::get(){return val;}
template<typename T> const T& S<T>::get() const {return val;}
template<typename T> void S<T>::set(T x) {val = x;}
template<typename T> void S<T>::operator=(const T& x){val = x;};
template<typename T> void read_val(T& v){    
    std::cin >> v;
};

template<typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        os << v[i];
        if (i<v.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> std::istream& operator>>(std::istream& is, std::vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        throw std::runtime_error("Badly given vector values.");
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}


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

    std::cout<<"Give an int, a character, a double, and a string (pressing enter after each.)\n";
    //examples
    int iexample;
    read_val(iexample);
    s_int.set(iexample);

    char cexample;
    read_val(cexample);
    s_char.set(cexample);

    double dexample;
    read_val(dexample);
    s_double.set(dexample);

    std::string sexample; // lol
    read_val(sexample);
    s_string.set(sexample);


    std::cout<<s_int.get()<<'\n';
    std::cout<<s_char.get()<<'\n';
    std::cout<<s_double.get()<<'\n';
    std::cout<<s_string.get()<<'\n';

    std::cout<<"Give a vector! \t { value, value, value }\n";
    std::vector<int> vexample;
    read_val(vexample);
    s_vector.set(vexample);

    std::cout<<s_vector.get()<<'\n';
    return 0;
}