#This is a makefile

CXX = clang++
CXXFLAGS = -g -Wall
SRCS = main.cpp
OBJS = main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	@$(CXX) -c main.cpp

run:
	@./$(TARGET)

clean:
	@rm -rf *.o *.exe *.out *~ *.dSYM $(TARGET)