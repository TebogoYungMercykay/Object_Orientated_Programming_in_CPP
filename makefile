main:
	g++ *.cpp -std=c++98 -pedantic -o main
run:
	valgrind --leak-check=full ./main
clean:
	rm -f *.o *.tar main
	clear
tar:
	tar -cvz makefile *.cpp -f FileName.tar
zip:
	tar -cvz makefile *.cpp -f FileName.zip
tar_gz:
	tar -cvz makefile *.cpp -f FileName.tar.gz
untar:
	tar -zxvf *.tar
unzip:
	tar -zxvf *.zip
untar_gz:
	tar -zxvf *.tar.gz
