test: temperature.o driver.o
	g++ -o test temperature.o driver.o

temperature.o: temperature.cpp temperature.h
	g++ -c temperature.cpp

driver.o: driver.cpp temperature.h
	g++ -c driver.cpp

clean:
	rm -f *.o test	
