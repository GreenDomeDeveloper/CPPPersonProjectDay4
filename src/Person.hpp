#ifndef PERSON_HPP
#define PERSON_HPP

#include<string>
using namespace std;

static int population = 0;

class Person {
    private:
        string name;
        int age;
        bool isValidAge(int);
    

    public:
        Person();
        Person(string, int);
        string getName();
        int getAge();
        void setName(string);
        void setAge(int);
        void hasBirthday();
        void printInfo();
        static int getPopulation();

        friend ostream& operator<<(ostream& os, const Person person);
        
};

#endif