main:
	g++ Cargo.cpp Passenger.cpp SecretCargo.cpp main.cpp -std=c++98 -pedantic -o main
run:
	./main
clean:
	rm -f *.o *.tar main
	clear
tar:
	tar -cvz *.h *.cpp -f Templates.tar
untar:
	tar -zxvf *.tar