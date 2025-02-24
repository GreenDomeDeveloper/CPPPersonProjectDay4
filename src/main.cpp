#include "Person.hpp"
#include <iostream>
using namespace std;

int main() {

    cout<<"\nCheck Population ...."<<endl;
    cout<<Person::getPopulation()<<endl;
    
    Person p1;
    Person p2("Mary Johnson",21);

    cout << p1 <<endl;
    cout << p2 <<endl;

    p1.setAge(60);
    p1.setName("Bob Williams");
    p2.hasBirthday();

    cout << "\nAfter updates ..."<<endl;
    p1.printInfo();
    p2.printInfo();

    cout<<"\nChecking Validation ..."<<endl;
    p2.setAge(500);
    Person p3("Larry Smith",-71);
    p2.printInfo();
    p3.printInfo();

    cout<<"\nCheck Population ...."<<endl;
    cout<<Person::getPopulation()<<endl;

    
    return 0;
} 