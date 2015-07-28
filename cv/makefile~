all: customVector.o vectorTest.o
	g++ customVector.o vectorTest.o -std=c++11 -o vectorTest

customVector.o: customVector.cpp
	g++ -c -std=c++11 customVector.cpp -o customVector.o
	
vectorTest.o: customVector.o vectorTest.cpp
	g++ -c -std=c++11 vectorTest.cpp -o vectorTest.o

clean:
	rm *.o vectorTest
