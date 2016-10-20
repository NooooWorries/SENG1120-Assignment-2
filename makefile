CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Node.h LinkedList.h DeckOfCards.cpp Blackjack.cpp Card.cpp HandOfCards.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
