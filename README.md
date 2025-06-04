# C++ Object-Oriented Programming Projects

<img src="images/readme.png" style="width: 100%; height: 40%;" />

Welcome to the **C++ Object-Oriented Programming Projects** repository! This collection showcases a variety of C++ projects that demonstrate core object-oriented programming (OOP) concepts, data structures, and algorithms. These projects are ideal for learners looking to deepen their understanding of C++ and OOP principles.

## Requirements

Before running the C++ code, ensure you have the following set up:

- **IDE Recommendation**: Install an IDE that supports C++ compilation and execution, such as **Visual Studio Code**.
- **Setting up WSL Ubuntu terminal**: Follow this [guide](https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s) to set up WSL on Visual Studio Code for a Linux-based terminal environment.
- **Compiler Path Configuration**: If you encounter issues with compiler paths in VS Code, refer to this [forum discussion](https://forums.unrealengine.com/t/ue-4-27-how-to-fix-issues-in-visual-studio-code-red-squiggles-and-unable-to-resolve-configuration-with-compilerpath-c-program/568488) for troubleshooting steps.

## Projects

- **Access Control Device**: Implements a simulated access control system.
- **BinaryHeap.cpp**: Demonstrates the implementation of a binary heap data structure.
- **Calculator Simulation Using Stacks**: A calculator application utilizing stack data structures.
- **Chess Imitation (Mate in One)**: Simulates a chess endgame scenario focusing on mate-in-one situations.
- **Classes and Array of Objects**: Showcases the use of classes and arrays of objects in C++.
- **Doubly Linked List**: Implementation of a doubly linked list data structure.
- **Encryption and Decryption**: A program demonstrating basic encryption and decryption techniques.
- **Genetic Algorithm**: An implementation of a simple genetic algorithm.
- **Linear Data Structures**: Examples of various linear data structures in C++.
- **Linked Lists and Recursion**: Demonstrates the use of linked lists with recursive algorithms.
- **Matrices**: Operations and manipulations on matrices.
- **Neural Networking**: A basic implementation of a neural network.
- **Operator Overloading**: Examples of operator overloading in C++.
- **Operator Overloading and Inheritance**: Combines concepts of operator overloading with inheritance.
- **Pointers to Objects**: Demonstrates the use of pointers with objects in C++.
- **Polymorphism**: Examples showcasing polymorphism in C++.
- **Singly Linked List**: Implementation of a singly linked list data structure.
- **Template Classes and Vectors**: Demonstrates the use of template classes and vectors in C++.

## Makefile

A Makefile is provided to simplify the process of compiling and running the C++ code via the terminal.

- Makefile Commands:
  - **`make`**: Compiles the `.cpp` files and generates an executable named `main`.
  - **`make run`**: Runs the executable using `valgrind` to check for memory leaks.
  - **`make clean`**: Removes the executable and object files, and clears the terminal.
  - **`make tar`**: Compresses the source files and the Makefile into a `.tar.gz` archive.
  - **`make untar`**: Extracts files from the `.tar.gz` archive.

- Makefile
	```Makefile
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

## Contributing

This project is primarily for personal learning and demonstration purposes. However, if you have suggestions for improvements, feel free to open an issue or submit a pull request.

To contribute:

1. Fork the repository.
2. Create a new branch for your feature or fix.
3. Commit your changes.
4. Submit a pull request with a clear description.

## License

This project is open source. Please refer to the repository for specific license details.

---