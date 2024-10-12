# C++ Object-Oriented Programming Projects

This repository contains a collection of C++ projects demonstrating various object-oriented programming concepts, data structures, and algorithms. These projects are designed to help learners understand and practice key OOP principles and common programming techniques.

## Requirements Before Running Codes

- Install an IDE that compiles and runs C++ codes. Recommendation: VS Code
- For WSL users: How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: [YouTube Tutorial](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s)

## About the Codes

- All code in this repository is written by the repository owner
- These programs were created as practice code, practical exercises, and assignments for coding modules

## Projects

1. **Access Control Device**: Implements a simulated access control system.
2. **BinaryHeap.cpp**: Demonstrates the implementation of a binary heap data structure.
3. **Calculator Simulation Using Stacks**: A calculator application utilizing stack data structures.
4. **Chess Imitation (Mate in One)**: Simulates a chess endgame scenario focusing on mate-in-one situations.
5. **Classes and Array of Objects**: Showcases the use of classes and arrays of objects in C++.
6. **Doubly Linked List**: Implementation of a doubly linked list data structure.
7. **Encryption and Decryption**: A program demonstrating basic encryption and decryption techniques.
8. **Genetic Algorithm**: An implementation of a simple genetic algorithm.
9. **Linear Data Structures**: Examples of various linear data structures in C++.
10. **Linked Lists and Recursion**: Demonstrates the use of linked lists with recursive algorithms.
11. **Matrices**: Operations and manipulations on matrices.
12. **Neural Networking**: A basic implementation of a neural network.
13. **Operator Overloading**: Examples of operator overloading in C++.
14. **Operator Overloading and Inheritance**: Combines concepts of operator overloading with inheritance.
15. **Pointers to Objects**: Demonstrates the use of pointers with objects in C++.
16. **Polymorphism**: Examples showcasing polymorphism in C++.
17. **Singly Linked List**: Implementation of a singly linked list data structure.
18. **Template Classes and Vectors**: Demonstrates the use of template classes and vectors in C++.

## Makefile

A Makefile is included to compile and run the codes on the terminal with the following commands:

```
make clean
make
make run
```

Here's the content of the Makefile:

```makefile
main:
	g++ -g *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o *.tar.gz main
	reset
	clear

run:
	valgrind --leak-check=full ./main

tar:
	tar -cvz *.* -f Code.tar.gz

untar:
	tar -zxvf *.tar.gz
```

## Getting Started

To run these projects:

1. Ensure you have a C++ compiler installed on your system.
2. Clone this repository to your local machine.
3. Navigate to the project directory you want to run.
4. Use the provided Makefile commands to compile and run the programs.

## Contributing

While this repository primarily contains personal practice code, contributions to improve existing projects or add new ones may be considered. If you'd like to contribute:

1. Fork the repository.
2. Create a new branch for your feature.
3. Add your changes.
4. Submit a pull request with a clear description of your improvements.

## License

This project is open source. Please check the repository for any specific license information.