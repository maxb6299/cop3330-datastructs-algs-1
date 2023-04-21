test: diamond.o driver.o
	g++ -o test diamond.o driver.o

diamond.o: diamond.cpp diamond.h
	g++ -c diamond.cpp

driver.o: driver.cpp diamond.h
	g++ -c driver.cpp

clean:
	rm -f *.o test
