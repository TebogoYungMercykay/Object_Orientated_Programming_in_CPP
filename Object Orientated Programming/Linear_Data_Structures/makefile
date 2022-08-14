main: main.o circularList.o linkedList.o dynamicArray.o stack.o orderedContainer.o queue.o priorityQueue.o
	c++ -static main.o circularList.o linkedList.o dynamicArray.o stack.o orderedContainer.o queue.o priorityQueue.o -o main

circularList.o: circularList.cpp circularList.h
	c++ -Wall -c circularList.cpp
	
dynamicArray.o: dynamicArray.cpp dynamicArray.h
	c++ -Wall -c dynamicArray.cpp	

linkedList.o: linkedList.cpp linkedList.h
	c++ -Wall -c linkedList.cpp
	
orderedContainer.o: orderedContainer.cpp orderedContainer.h
	c++ -Wall -c orderedContainer.cpp	
	
stack.o: stack.cpp stack.h
	c++ -Wall -c stack.cpp	
	
queue.o: queue.cpp queue.h
	c++ -Wall -c queue.cpp	
	
priorityQueue.o: priorityQueue.cpp priorityQueue.h
	c++ -Wall -c priorityQueue.cpp
	
main.o: main.cpp
	c++ -Wall -c main.cpp

clean:
	rm *.o main

run:
	./main

tar:
	tar -cvz *.cpp *.h makefile -f A4.tar.gz
	
	
