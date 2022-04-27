#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
template<typename Iter1, typename Iter2, typename p> 
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

struct Item
{
    std::string name;
    int iid;
    double value;
    
    public:
        Item(std::string n, int id, double v){name=n;iid=id;value=v;}
        Item(){}
        std::string getName(){return name;}
        int getID(){return iid;}
        double getValue(){return value;}
};
std::ostream& operator<<(std::ostream& os, Item& i){
    os<<i.getName()<<"; "<<i.getID()<<"; "<<i.getValue();
    return os;
}
std::istream& operator>>(std::istream& is, Item& i){
    int id;
    double v;
    std::string n;
    std::string help;
    std::getline(is,n);
    std::getline(is,help,' ');
    if (help!="")
        id = std::stoi(help);
    
    std::getline(is,help);
    if (help!="")
        v = std::stod(help);

    i = Item{n,id,v};
    return is;
}
template<typename T> void print(T vec, std::string cap){
    
    std::cout<<"\n\n"<<cap<<"\n\n";
    for (auto& i : vec)
    {
        std::cout<<i<<'\n';
    }
    
}
template<typename Iterator, typename Predicate>
Iterator myfind(Iterator first, Iterator last, Predicate pred){
    while (first != last && !pred(*first))
    {
        first++;
    }
    return first;
}
template<typename T>
void readFromFile(std::string filename, T& v){
    std::ifstream ins {filename};
    for (Item i; ins>>i;)
    {
        v.push_back(i);
    }

}


struct Compare_by_name
{
    bool operator()(const Item& a, const Item& b) const {return a.name<b.name;}
};
struct Compare_by_iid
{
    bool operator()(const Item& a, const Item& b) const {return a.iid<b.iid;}
};
struct Compare_by_value
{
    bool operator()(const Item& a, const Item& b) const {return a.value>b.value;}
};
struct Name_eq
{
    std::string n;
    public:
        Name_eq(std::string name){n=name;}
        bool operator()(const Item& a) const {return n == a.name;}
};
struct Iid_eq
{
    int id;
    public:
        Iid_eq(int iid){id=iid;}
        bool operator()(const Item& a) const {return id == a.iid;}
};



int main(){

    std::string filename = "file.txt";

    //---Vector

    std::vector<Item> vi;

    readFromFile(filename,vi);
    
    print(vi,"Vecor:");

    std::sort(vi.begin(),vi.end(), Compare_by_name()); // sort by name
    std::sort(vi.begin(),vi.end(), Compare_by_iid()); // sort by iid
    std::sort(vi.begin(),vi.end(), Compare_by_value()); // sort by value
    
    print(vi,"Vector after sort by value:");

    vi.push_back(Item{"horse shoe",99,12.34});
    vi.push_back(Item{"Canon S400",9988,499.95});
    print(vi,"Inserting two:");
    vi.erase(myfind(vi.begin(),vi.end(),Name_eq{"soap"}));
    vi.erase(myfind(vi.begin(),vi.end(),Name_eq{"orange peel"}));
    print(vi,"Erasing soap and orange peel:");
    vi.erase(myfind(vi.begin(),vi.end(),Iid_eq{1}));
    vi.erase(myfind(vi.begin(),vi.end(),Iid_eq{3}));
    print(vi,"Erasing items with the id of 1 and 3: ");

    //---List

    std::list<Item> li;
    readFromFile(filename,li);
    print(li,"List:");
    li.sort([](const Item& a, const Item& b){return a.name<b.name;});
    print(li,"Sort by name:");
    li.sort(Compare_by_iid());
    li.sort(Compare_by_value());

    print(li,"List after sort by value:");

    li.push_back(Item{"horse shoe",99,12.34});
    li.push_back(Item{"Canon S400",9988,499.95});
    print(li,"Inserting two:");
    li.erase(myfind(li.begin(),li.end(),Name_eq{"soap"}));
    li.erase(myfind(li.begin(),li.end(),Name_eq{"orange peel"}));
    print(li,"Erasing soap and orange peel:");
    li.erase(myfind(li.begin(),li.end(),Iid_eq{1}));
    li.erase(myfind(li.begin(),li.end(),Iid_eq{3}));
    print(li,"Erasing items with the id of 1 and 3: ");

  //---Map

}