# Person Class CMake Project

A simple Person class built with CMake.

## Prerequisites

- CMake (version 3.10 or higher)
- C++ compiler (supporting C++17)

## Project Structure

```
. 
├──  # Root CMake configuration 
├── src/  
│ ├── Person.cpp # Person class implementation 
│ ├── Person.hpp # Person class declaration 
│ └── main.cpp # Main source file 
├── .gitignore  
├── LICENSE 
└── README.md
```

## Person Class Overview

The `Person` class demonstrates various C++ concepts including constructors, destructors, memory management, operator overloading, and encapsulation. It tracks a global population count of all Person objects.

### Private Member Variables

- `name`: A string representing the person's full name.
- `age`: An integer representing the person's age in years.
- `nickname`: A dynamically allocated C-string for the person's nickname.
- `isValidAge(int)`: A helper method that validates if an age is between 0 and 120.

### Public Member Functions

#### Constructors and Destructor
- `Person()`: Default constructor that initializes name to "John Doe", age to 42, and nickname to "Buddy".
- `Person(string name, int age)`: Constructor that sets name and age (if valid), with default nickname "Buddy".
- `Person(string name, int age, char* nickname)`: Constructor that sets name, age (if valid), and copies the provided nickname.
- `Person(const Person& other)`: Copy constructor that creates a deep copy of another Person object.
- `~Person()`: Destructor that frees dynamically allocated memory and decrements the population count.

#### Getters
- `string getName()`: Returns the person's name.
- `int getAge()`: Returns the person's age.
- `char* getNickname()`: Returns a pointer to the person's nickname.
- `static int getPopulation()`: Returns the total count of Person objects.

#### Setters
- `void setName(string name)`: Sets the person's name.
- `void setAge(int age)`: Sets the person's age if the value is valid (0-120).
- `void setNickname(char* nickname)`: Sets the person's nickname, managing memory appropriately.

#### Other Methods
- `void hasBirthday()`: Increments the person's age by one.
- `void printInfo()`: Prints the person's information to the console.

#### Operator Overloads
- `Person& operator=(const Person& other)`: Assignment operator that performs a deep copy.
- `friend ostream& operator<<(ostream& os, const Person& person)`: Stream insertion operator for easy output.

### Static Members
- `population`: A static variable that tracks the total number of Person objects.

## Memory Management

The `Person` class demonstrates proper memory management for dynamically allocated resources:
- Allocates memory for the nickname in constructors
- Properly deallocates memory in the destructor and when setting a new nickname
- Implements deep copying in the copy constructor and assignment operator
- Handles self-assignment in the assignment operator

## Building the Project

1. Create and enter a build directory:
   ```bash
   mkdir build
   cd build
   ```

2. Generate build files:
   ```bash
   cmake ..
   ```

3. Build the project:
   ```bash
   make
   ```

## Running the Program

After building, run the program from the build directory:

```bash
./PersonProject
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
