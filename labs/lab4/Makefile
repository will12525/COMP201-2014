CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp model.cpp view.cpp controller.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab4.exe

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o $(EXECUTABLE)
