#ifndef PERSON_HPP
#define PERSON_HPP

#include<string>
#include<cstring>
using namespace std;

// Global static variable to track the total number of Person objects
static int population = 0;

/**
 * @class Person
 * @brief Represents a person with basic attributes like name, age, and nickname
 * 
 * This class demonstrates various C++ concepts including:
 * - Constructors and destructors
 * - Copy constructor and assignment operator
 * - Memory management for dynamically allocated resources
 * - Encapsulation with getters and setters
 * - Static class members
 * - Friend functions
 */
class Person {
    private:
        string name;      // Person's full name
        int age;          // Person's age in years
        char* nickname;   // Dynamically allocated C-string for nickname
        
        /**
         * @brief Validates if an age value is within acceptable range
         * @param age The age to validate
         * @return true if age is between 0 and 120, false otherwise
         */
        bool isValidAge(int);
    

    public:
        /**
         * @brief Default constructor
         * Creates a Person with default values: name="John Doe", age=42, nickname="Buddy"
         */
        Person();
        
        /**
         * @brief Constructor with name and age
         * @param name The person's name
         * @param age The person's age (will be validated)
         */
        Person(string, int);
        
        /**
         * @brief Constructor with name, age and nickname
         * @param name The person's name
         * @param age The person's age (will be validated)
         * @param nickname The person's nickname (will be copied)
         */
        Person(string, int, char*);
        
        /**
         * @brief Copy constructor
         * @param other The Person object to copy from
         */
        Person(const Person&);
        
        /**
         * @brief Destructor
         * Frees dynamically allocated memory and decrements population
         */
        ~Person();
        
        /**
         * @brief Gets the person's name
         * @return The person's name as a string
         */
        string getName();
        
        /**
         * @brief Gets the person's age
         * @return The person's age as an integer
         */
        int getAge();
        
        /**
         * @brief Gets the person's nickname
         * @return Pointer to the person's nickname as a C-string
         */
        char* getNickname();
        
        /**
         * @brief Sets the person's name
         * @param name The new name to set
         */
        void setName(string);
        
        /**
         * @brief Sets the person's age if valid
         * @param age The new age to set (must be between 0-120)
         */
        void setAge(int);
        
        /**
         * @brief Sets the person's nickname
         * @param nickname The new nickname to set
         */
        void setNickname(char*);
        
        /**
         * @brief Increments the person's age by 1
         */
        void hasBirthday();
        
        /**
         * @brief Prints the person's information to console
         */
        void printInfo();
        
        /**
         * @brief Gets the total population (number of Person objects)
         * @return The current population count
         */
        static int getPopulation();

        /**
         * @brief Overloaded stream insertion operator
         * @param os The output stream
         * @param person The Person object to output
         * @return Reference to the output stream
         */
        friend ostream& operator<<(ostream& os, const Person& person);
        
        /**
         * @brief Overloaded assignment operator
         * @param originPerson The Person object to copy from
         * @return Reference to the current Person object
         */
        Person& operator=(const Person& originPerson);
        
};

#endif