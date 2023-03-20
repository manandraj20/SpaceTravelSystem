

# Makefile

# Compiler settings
CC = g++
CFLAGS = -Wall -g
INCLUDE = -I.

# Files
SRCS = main.cpp Traveller.cpp Ticket.cpp Planet.cpp Date.cpp SpaceTravel.cpp Passenger.cpp mars.cpp earth.cpp jupiter.cpp pluto.cpp moon.cpp saturn.cpp
OBJS = $(SRCS:.cpp=.o)

# Targets
all: main

main: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Clean target
clean:
	rm -f $(OBJS) main
