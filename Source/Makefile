# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Source

# GNU C++ Compiler
CPP         = g++      # C++ Compuler

# compiler flags -g debug, -O2 optimized version -c create a library object
#CPPFLAGS    = -O3 -c 
CPPFLAGS    = -O2 -Wall -Warray-bounds -c
CPPFLAGS2   = -std=c++11 -c

# The directory where the include files needed to create the library objects are
INC_DIR = ../Include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../Lib

# DATA_OBJS contains the current list of object files created after 
# compiling the C++ source files that declare and implement OO classes 
CA_OBJS = CellularAutomata.o

# DATA_LIB is the name of object library file that will contain all
# DATA_OBJS files
CA_LIB = libmyCA.a 

CellularAutomata.o: $(INC_DIR)/myCA.h
	$(CPP) $(CPPFLAGS2) CellularAutomata.cpp -I$(INC_DIR)

libmyCA.a: $(CA_OBJS)
	ar ru $(CA_LIB) $(CA_OBJS) 
	mv $(CA_LIB) $(LIB_DIR)
	rm $(CA_OBJS)
    
all: $(CA_LIB)

cleanall:
	cd $(LIB_DIR); rm $(CA_LIB)