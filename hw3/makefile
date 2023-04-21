test: time.o driver.o
	g++ time.o driver.o -o test

time.o: time.cpp time.h
	g++ -c time.cpp

driver.o: driver.cpp time.h
	g++ -c driver.cpp

clean:
	rm -f *.o test	
