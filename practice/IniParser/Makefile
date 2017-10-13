all: parser

IniLineParser.o: IniLineParser.hpp IniLineParser.cpp
	g++ -c IniLineParser.cpp -I. -o IniLineParser.o

main.o: IniLineParser.hpp main.cpp
	g++ -c main.cpp -I. -o main.o

parser: IniLineParser.o main.o
	g++ -o parser IniLineParser.o main.o

clean:
	@rm -rf *.o parser
