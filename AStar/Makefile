TARGET=astar
MODULES=main.o astar_search.o Node.o util.o
CPPFLAGS=-ansi -pedantic-errors -Wall -std=c++17	

$(TARGET): $(MODULES) 
	g++ $(MODULES) -o $(TARGET)

main.o: main.cpp 

astar_search.o: astar_search.hpp astar_search.cpp

Node.o: Node.hpp Node.cpp

util.o: util.hpp util.cpp

clean:
	rm *o
all: clean astar


