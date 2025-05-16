all:
	g++ -Wall -Wextra -Wpedantic -Werror -Wconversion -Wsign-conversion -Wshadow -Wnull-dereference -Wfloat-equal -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wformat=2 -Wcast-align -Wstrict-overflow=5 -Wunsafe-loop-optimizations -Wuseless-cast -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wnon-virtual-dtor -Wzero-as-null-pointer-constant -Wmissing-declarations -Weffc++ -Wstack-protector -o run Ej_1/Plane.cpp Ej_1/main1.cpp main.cpp

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./run
	rm run