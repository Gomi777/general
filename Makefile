test: main.o project1.o
	g++ -o test main.o project1.o

main.o: main.cpp
	g++ -c main.cpp

project1.o: project1.cpp project1.h
		g++ -c project1.cpp

clean:
	rm -f test main.o project1.o