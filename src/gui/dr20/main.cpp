#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <list>
#include <array>
#include <algorithm>

template<typename Iter1, typename Iter2>
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2){
    if (f1==e1)
    {
        return f2;
    }
    Iter1 it;
    for(it = f1; it!=e1; ++it){
            *++f2 = *it;
    }
    return f2;
}

template<typename T> void writeout(const T& data, std::string head){
    std::cout<<head<<"\n\t";
    for (auto& x : data)
    {
        std::cout<<x<<' ';
    }
    std::cout<<"\n\n";
}

int main (){

    int array10[] = {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vector10 = {0,1,2,3,4,5,6,7,8,9};
    std::list<int> list10 = {0,1,2,3,4,5,6,7,8,9};

    writeout(array10,"array10:");
    writeout(vector10,"vector10:");
    writeout(list10,"list10:");


    int array_copy[10];
    for (int i = 0; i < 10; i++)
    {
        array_copy[i]=array10[i];
    }
    
    std::vector<int> vector_copy = vector10;
    std::list<int> list_copy = list10;
    writeout(array_copy,"array_copy:");
    writeout(vector_copy,"vector_copy:");
    writeout(list_copy,"list_copy:");
    

    
    for (int i = 0; i < 10; i++)
    {
        array_copy[i] = array_copy[i]+2;
        vector_copy[i] = vector_copy[i]+3;
    }
    std::list<int>::iterator it;
    for (it = list_copy.begin(); it !=list_copy.end(); it++){
        *it = (*it)+5;
    }
    
    std::cout<<"\n\nModify the elements in the array, the vector, and the list.\n\n";

    writeout(array_copy,"The new array:");
    writeout(vector_copy,"The new vector:");
    writeout(list_copy,"The new list:");
    
    std::array<int,10> array2 = {9,8,7,6,5,4,3,2,1,0};
    writeout(array2,"array2:");

    copy(array2.begin(),array2.end(),vector_copy.begin());
    writeout(vector_copy,"Lets copy the array2 into the vector:");

    copy(list_copy.begin(),list_copy.end(),array2.begin());
    writeout(list_copy,"Now lets copy the list into array2:");
    
    auto f = std::find(vector_copy.begin(),vector_copy.end(),3);
    if(f!=vector_copy.end()){
        std::cout<<"The vector contains the value 3"<<"\nPosition: "<<f-vector_copy.begin()<<'\n';
    }else
        std::cout<<"The vector does not contain the value 3\n";

    auto f2 = std::find(list_copy.begin(),list_copy.end(),27);
    
    if(f2!=list_copy.end()){
        std::cout<<"The list contains the value 27"<<"\nPosition: "<<f-vector_copy.begin()<<'\n';
    }else
        std::cout<<"The list does not contain the value 27\n";
    
    return 0;
}