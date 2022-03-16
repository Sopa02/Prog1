#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void error(string s){
    throw runtime_error(s);
}

struct Person
{
    private:
        string first_name;
        string second_name;
        int age;
    public:
        Person(string fn, string sn, int a){
            
            if (a<=0 || a>150)
            {
                error("Invalid age!");
            }
            string invalid[] = {";",":","\"","\'","*","&","^","%","$","#","@","!","[","]"};
            for (int i = 0; i < 13; i++)
            {
                if (fn.find(invalid[i])<fn.length() || sn.find(invalid[i])<sn.length())
                {
                    error("Invalid name!");
                }
                
            }
            first_name=fn;
            second_name=sn;
            age=a;
        }

        Person(){}
        int getAge() const{
            return age;
        }
        string getName() const{
            return first_name+" "+second_name;
        }
        string getFirstName() const{
            return first_name;
        }
        string getSecondName() const{
            return second_name;
        }
};

istream& operator>>(istream& is, Person& p){
    int age;
    string fName, sName;
    is>>fName>>sName>>age;
    p = Person{fName,sName,age};
    return is;
}

ostream& operator<<(ostream& os, Person& p){
    return os<<"Name: "<<p.getName()<<"\nAge: "<<p.getAge()<<"\n";
}

int main(){
    using namespace std;

    Person Goofy{"Goofy","Goof",63};
    cout<<"Name: "<<Goofy.getName()<<"\nAge: "<<Goofy.getAge()<<"\n";
    cout<<"Give a name and an age, divided by a space character, then press enter.\n"
    <<"Do this 5 times to give 5 different persons\n";
    
    vector<Person> pv;
    for (int i = 0; i < 5; i++)
    {
        Person given;
        cin>>given;
        pv.push_back(given);
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout<<pv[i];
    }
    


    return 0;
}