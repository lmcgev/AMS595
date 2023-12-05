# Makefile for the project compiles all the files and creates executable HW2main
#Note: On my computer I had to use command mingw32-make instead of just make. I'm not sure why but if you have a problem running this try that

#object files, compiler type, compiler flags
OBJECTS = HW2main.o pi_approx.o approximations.o
CXX = g++
CXXflags = -std=c++17

#Targets for the file
HW2main : $(OBJECTS)
	$(CXX) $(OBJECTS) -o HW2main

HW2main.o : HW2main.cpp
	@$(CXX) $(CXXflags) HW2main.cpp -c

pi_approx.o : pi_approx.cpp
	@$(CXX) $(CXXflags) pi_approx.cpp -c

approximations.o : approximations.cpp
	@$(CXX) $(CXXflags) approximations.cpp -c

#rule to remove all object files in current directory 
clean : 
	@echo "Removing all object files and executables..."
	rm *.o HW2main