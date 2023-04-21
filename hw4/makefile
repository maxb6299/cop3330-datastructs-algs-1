test: menu.o store.o book.o
	g++ $^ -o test

menu.o: menu.cpp store.h book.h
	g++ -c menu.cpp

store.o: store.h store.cpp book.h
	g++ -c store.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

clean: 
	rm -f *.o *.gch test 