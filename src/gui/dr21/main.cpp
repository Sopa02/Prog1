#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>

struct Item{
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
    os<<i.getName()<<';'<<i.getID()<<';'<<i.getValue();
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


void readFromFile(std::string filename, std::vector<Item>& v){
    std::ifstream ins {filename};
    for (Item i; ins>>i;)
    {
        v.push_back(i);
    }

}
void readFromFile(std::string filename, std::list<Item>& l){
    std::ifstream ins {filename};
    for (Item i; ins>>i;)
    {
        l.push_back(i);
    }
    
}

int main(){

    std::string filename = "file.txt";

    //---Vector
    std::cout<<"Vector:\n\n";

    std::vector<Item> vi;

    readFromFile(filename,vi);
    
    for (Item i : vi)
    {
        std::cout<<i<<"\n";
    }
    
    //---List
    std::cout<<"\n\nList:\n\n";

    std::list<Item> li;
    readFromFile(filename,li);
    for (Item i : li)
    {
        std::cout<<i<<"\n";
    }

    //---Map

}