test: myint.o main.o
	g++ $^ -o test

main.o: myint.h main.cpp
	g++ -c main.cpp

myint.o: myint.h myint.cpp
	g++ -c myint.cpp

clean: 
	rm *.o *.h.gch test
