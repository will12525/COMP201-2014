all: lab4

lab4: main.o model.o view.o controller.o
	g++ main.o model.o view.o controller.o -o lab4.exe

main.o:
	g++ -c main.cpp

model.o:
	g++ -c model.cpp

view.o:
	g++ -c view.cpp

controller.o:
	g++ -c controller.cpp
