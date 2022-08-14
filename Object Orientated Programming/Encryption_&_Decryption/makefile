main:
	g++ *.o -o main

object:
	g++ -c *.cpp -std=c++98 -pedantic

run: main
	./main

clean:
	rm  -f *.o main

tar:
	tar -cvz *.cpp *.h makefile -f Assignemnt3.tar