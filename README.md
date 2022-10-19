________________________________________________________________________________________

#                         C++ Programming                               
________________________________________________________________________________________
- ### Requirements before running codes:
    - Install an IDE that compiles and runs C++ codes. Recommendation VS Code
    - How to setup WSL Ubuntu terminal shell and run it from Visual Studio Code: https://www.youtube.com/watch?v=fp45HpZuhS8&t=112s
- ### About Codes:
    - The code is all written by myself only
    - I hard code them as part of my practice code, practical and assignemnts for my coding modules.
- ###  About Me: 
    - Tebogo Sello Selepe
    - Computer Sciences at Tuks
________________________________________________________________________________________
 ## Makefile
 ##### NB: A makefile Is Included to compile and run the codes on the terminal commands:=
- make clean
- make
- make run


```C++
main:
	g++ *.cpp -std=c++98 -pedantic -o main

clean:
	rm -f *.o main

run:
	./main

tar:
	tar -cvz *.h *.cpp -f Code.tar.gz```
________________________________________________________________________________________
