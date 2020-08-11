# Target: programa principal
main: main.o readFile.o handlerContext.o context.o
	g++ -o main main.o readFile.o handlerContext.o context.o

main.o: main.cpp	
	g++ -c main.cpp 

handlerContext.o: handlerContext.cpp handlerContext.hpp
	g++ -c handlerContext.cpp

readFile.o: readFile.cpp readFile.hpp
	g++ -c readFile.cpp

context.o: context.cpp context.hpp
	g++ -c context.cpp

clean:
	rm *.o main	