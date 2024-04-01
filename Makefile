#This is a makefile

CXX = clang++
CXXFLAGS = -g -Wall
SRCS = main.cpp func.cpp exceptions.cpp
OBJS = main.o func.o exceptions.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	@$(CXX) -c -std=c++20 main.cpp

func.o: func.cpp
	@$(CXX) -c -std=c++20 func.cpp

exceptions.o: exceptions.cpp
	@$(CXX) -c -std=c++20 exceptions.cpp

run:
	@./$(TARGET)

clean:
	@rm -rf *.o *.exe *.out *~ *.dSYM $(TARGET)