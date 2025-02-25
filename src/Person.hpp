#ifndef PERSON_HPP
#define PERSON_HPP

#include<string>
#include<cstring>
using namespace std;

static int population = 0;

class Person {
    private:
        string name;
        int age;
        char* nickname;
        bool isValidAge(int);
    

    public:
        Person();
        Person(string, int);
        Person(string,int,char*);
        Person(const Person&);
        ~Person();
        string getName();
        int getAge();
        char* getNickname();
        void setName(string);
        void setAge(int);
        void setNickname(char*);
        void hasBirthday();
        void printInfo();
        static int getPopulation();

        friend ostream& operator<<(ostream& os, const Person person);
        Person& operator=(const Person& originPerson);
        
};

#endif