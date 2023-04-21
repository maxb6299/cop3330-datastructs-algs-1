a.out: menu.o studentlist.o student.o
	g++ $^

menu.o: menu.cpp studentlist.h student.h
	g++ -c menu.cpp

studentlist.o: studentlist.h studentlist.cpp student.h
	g++ -c studentlist.cpp

student.o: student.h student.cpp
	g++ -c student.cpp

clean: 
	rm *.o a.out *.h.gch