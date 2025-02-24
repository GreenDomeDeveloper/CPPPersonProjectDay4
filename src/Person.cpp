#include "Person.hpp"
#include <iostream>
using namespace std;

Person::Person():name("John Doe"),age(42)
{
    population++;
}

Person::Person(string newName, int newAge):name(newName)
{
    // name = newName;
    population++;
    if (isValidAge(newAge)){
       age = newAge; 
    } else {
        age = 42;
    }
    
}

string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

void Person::setName(string name)
{
    this->name = name;
}

void Person::setAge(int newAge)
{
    if (isValidAge(newAge)){
        age = newAge;
    }
    
}

void Person::hasBirthday()
{
    age++;
}

void Person::printInfo()
{
    cout<<name<<" is "<<age<<" years old."<<endl;
}

int Person::getPopulation()
{
    return population;
}

bool Person::isValidAge(int age)
{
    if ((age>=0)&& (age<=120)){
        return true;
    } else {
        return false;
    }
}

ostream &operator<<(ostream &os, const Person person)
{
    os<<person.name<<" is "<<person.age<<" years old.";
    return os;
}
