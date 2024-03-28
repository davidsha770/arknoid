CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -Werror -Wconversion -g -Wextra
CXXFLAGS+= -std=c++17
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -I ./brick -I ./ball -I ./surfase




# implicitly 

check: main
	./main


main:main.o ball/ball.o surfase/surfase.o brick/brick.o manager.o screen.o sub_man.o

main.o:main.cpp

manager.o: screen.hpp

ball.o: ball.cpp ball.hpp


info:
	@echo "function templates demo"
	@echo "may the force be with you!"

clean:
	@echo "cleaning up"
	$(RM) **/*.o  main  *.o  *.txt