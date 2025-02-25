#include "Person.hpp"
#include <iostream>
#include <cstring>
using namespace std;

/**
 * Default constructor
 * Initializes a Person with default values and increments the population counter
 */
Person::Person():name("John Doe"),age(42)
{
    population++;
    nickname = new char[strlen("Buddy")+1];
    strcpy(nickname,"Buddy");
}

/**
 * Constructor with name and age parameters
 * Uses member initialization list for name, validates age, and sets default nickname
 */
Person::Person(string newName, int newAge):name(newName)
{
    // name = newName; // Already set in initialization list
    population++;
    if (isValidAge(newAge)){
       age = newAge; 
    } else {
        age = 42;  // Default age if invalid age provided
    }
    nickname = new char[strlen("Buddy")+1];
    strcpy(nickname,"Buddy");
    
}

/**
 * Constructor with name, age, and nickname parameters
 * Uses member initialization list for name, validates age, and copies the provided nickname
 */
Person::Person(string newName, int newAge, char *newNickname):name(newName)
{
    population++;
    if (isValidAge(newAge)){
       age = newAge; 
    } else {
        age = 42;  // Default age if invalid age provided
    }
    nickname = new char[strlen(newNickname)+1];
    strcpy(nickname,newNickname);
}

/**
 * Copy constructor
 * Creates a deep copy of another Person object and increments population
 */
Person::Person(const Person &oldPerson)
{
    population++;
    name = oldPerson.name;
    age = oldPerson.age;
    nickname = new char[strlen(oldPerson.nickname)+1];
    strcpy(nickname,oldPerson.nickname);
}

/**
 * Destructor
 * Decrements population counter and frees dynamically allocated memory
 */
Person::~Person()
{
    population--;
    delete nickname;
}

/**
 * Gets the person's name
 */
string Person::getName()
{
    return name;
}

/**
 * Gets the person's age
 */
int Person::getAge()
{
    return age;
}

/**
 * Gets the person's nickname
 * Returns a pointer to the internal nickname (not a copy)
 */
char *Person::getNickname()
{
    return nickname;
}

/**
 * Sets the person's name
 * Uses 'this' pointer to disambiguate between parameter and member variable
 */
void Person::setName(string name)
{
    this->name = name;
}

/**
 * Sets the person's age if the provided value is valid
 * Does nothing if the age is invalid
 */
void Person::setAge(int newAge)
{
    if (isValidAge(newAge)){
        age = newAge;
    }
    
}

/**
 * Sets the person's nickname
 * Deallocates the old nickname and allocates memory for the new one
 */
void Person::setNickname(char * newNickname)
{
    delete nickname;
    nickname = new char[strlen(newNickname)+1];
    strcpy(nickname,newNickname);
}

/**
 * Increments the person's age by 1 (simulates having a birthday)
 */
void Person::hasBirthday()
{
    age++;
}

/**
 * Prints the person's information to the console
 */
void Person::printInfo()
{
    cout<<name<<" is "<<age<<" years old. Their nickname is "<<nickname<<"."<<endl;
}

/**
 * Static method to get the current population count
 */
int Person::getPopulation()
{
    return population;
}

/**
 * Overloaded assignment operator
 * Performs a deep copy of the source object if it's different from this object
 * Returns a reference to the current object to allow for chained assignments
 */
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

/**
 * Helper method to validate age values
 * Ages must be between 0 and 120 inclusive
 */
bool Person::isValidAge(int age)
{
    if ((age>=0)&& (age<=120)){
        return true;
    } else {
        return false;
    }
}

/**
 * Overloaded stream insertion operator (<<)
 * Allows Person objects to be directly inserted into output streams
 * Implemented as a friend function to access private members
 */
ostream &operator<<(ostream &os, const Person &person)
{
    os<<person.name<<" is "<<person.age<<" years old. Their nickname is "<<person.nickname<<".";
    return os;
}
