polycalculator.out: main.o polycalculator.o linkedlist.o
	g++ main.o polycalculator.o linkedlist.o -o polycalculator.out
main.o: main.cpp
	g++ -c  main.cpp
polycalculator.o: polycalculator.cpp polycalculator.h
	g++ -c polycalculator.cpp
linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c linkedlist.cpp
clean:
	rm *.o *.out