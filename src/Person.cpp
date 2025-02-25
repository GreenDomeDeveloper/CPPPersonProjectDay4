#include "Person.hpp"
#include <iostream>
#include <cstring>
using namespace std;

Person::Person():name("John Doe"),age(42)
{
    population++;
    nickname = new char[strlen("Buddy")+1];
    strcpy(nickname,"Buddy");
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
    nickname = new char[strlen("Buddy")+1];
    strcpy(nickname,"Buddy");
    
}

Person::Person(string newName, int newAge, char *newNickname):name(newName)
{
    population++;
    if (isValidAge(newAge)){
       age = newAge; 
    } else {
        age = 42;
    }
    nickname = new char[strlen(newNickname)+1];
    strcpy(nickname,newNickname);

}

Person::Person(const Person &oldPerson)
{
    population++;
    name = oldPerson.name;
    age = oldPerson.age;
    nickname = new char[strlen(oldPerson.nickname)+1];
    strcpy(nickname,oldPerson.nickname);
}

Person::~Person()
{
    population--;
    delete nickname;
}

string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

char *Person::getNickname()
{
    return nickname;
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

void Person::setNickname(char * newNickname)
{
    delete nickname;
    nickname = new char[strlen(newNickname)+1];
    strcpy(nickname,newNickname);
}

void Person::hasBirthday()
{
    age++;
}

void Person::printInfo()
{
    cout<<name<<" is "<<age<<" years old. Their nickname is "<<nickname<<"."<<endl;
}

int Person::getPopulation()
{
    return population;
}

Person &Person::operator=(const Person &originPerson)
{
    if (this != &originPerson){
        name = originPerson.name;
        age = originPerson.age;
        delete nickname;
        nickname = new char[strlen(originPerson.nickname)+1];
        strcpy(nickname,originPerson.nickname);
    }
    return *this;
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
    os<<person.name<<" is "<<person.age<<" years old. Their nickname is "<<person.nickname<<".";
    return os;
}
