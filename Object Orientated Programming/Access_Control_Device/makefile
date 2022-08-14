assign3.out: main.o ContactlessDevice.o PalmVein.o FacialRecognition.o
	g++ main.o ContactlessDevice.o PalmVein.o FacialRecognition.o -o assign3.out

main.o: main.cpp
	g++ -c main.cpp

ContactlessDevice.o: ContactlessDevice.cpp
	g++ -c ContactlessDevice.cpp

PalmVein.o: PalmVein.cpp
	g++ -c PalmVein.cpp

FacialRecognition.o: FacialRecognition.cpp
	g++ -c FacialRecognition.cpp

run:
	./assign3.out

clean:
	rm*.o assign3

