# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

TestCode: TestCode.o PIDControl.o Elevator.o
	$(CXX) $(CXXFLAGS) -o TestCode TestCode.o PIDControl.o Elevator.o

# The main.o target can be written more simply

TestCode.o: TestCode.cpp PIDControl.h Elevator.h
	$(CXX) $(CXXFLAGS) -c TestCode.cpp

PIDControl.o: PIDControl.h

Elevator.o: Elevator.h PIDControl.h