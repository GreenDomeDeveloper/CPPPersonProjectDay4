# Hello World CMake Project

A simple Hello World program built with CMake.

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

The `Person` class is a simple representation of a person with a name and age. It provides functionality to get and set these attributes, as well as increment the age.

### Private Member Variables

- `name`: A string representing the name of the person.
- `age`: An integer representing the age of the person.

### Public Member Functions

- `string getName()`: Returns the name of the person.
- `int getAge()`: Returns the age of the person.
- `void setName(string newName)`: Sets the name of the person.
- `void setAge(int newAge)`: Sets the age of the person.
- `void hasBirthday()`: Increments the age of the person by one.

### Constructors

- `Person()`: Default constructor that initializes the name to "John Doe" and the age to 42.
- `Person(string newName, int newAge)`: Parameterized constructor that allows setting the name and age.

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
