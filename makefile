# Target: programa principal
main: readFile.o context.o
	g++ -o main readFile.o context.o

readFile.o: readFile.cpp context.hpp
	g++ -c readFile.cpp

context.o: context.cpp context.hpp
	g++ -c context.cpp

clean:
	rm *.o main	