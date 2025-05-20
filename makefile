CXX       = g++
CXXFLAGS  = -std=c++17 -Wall

SRC       = $(shell find Ej_1 Ej_2 -name "*.cpp") main.cpp
EXEC      = main.exe

.PHONY: all clean

all: clean $(EXEC)
	@valgrind --leak-check=full --track-origins=yes ./$(EXEC)

$(EXEC):
	@$(CXX) $(CXXFLAGS) $(SRC) -o $(EXEC)

clean:
	@rm -f $(EXEC)

