# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Tests


# GNU C++ Compiler
CPP         = g++      

# other compiler flags -g debug, -c create a library object
CPPFLAGS    = -O0 -o
CPPFLAGS2	= -std=c++11 -O0 -o
CPPFLAGSANITIZER = -std=c++11 -O0  -g -fsanitize=address -o
CPPFLAGVALGRIND = -std=c++11 -O0  -g -o

# The directory where the include files needed to create the library objects are
UINC_DIR = ../Utils/Include

# The directory where all object files are going to be moved after creation
ULIB_DIR    = ../Utils/Lib
BIN_DIR     = ../Bin
INC_DIR     = ../Include
LIB_DIR     = ../Lib

# The next line contains the list of object files created by this Makefile.
EXECUTABLES =  test_CA_setup test_FixedBound_TransNeigh test_FixedBound_Trans \
				test_FixedBound_Majority test_PeriodicBound_Majority test_PeriodicBound_Trans \
				test_PeriodicBound_TransNeigh test_NoBound_Majority test_NoBound_Trans \
				test_NoBound_TransNeigh test_localized_init 

test_CA_setup:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_CA_setup test_CA_setup.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_CA_setup $(BIN_DIR)

test_FixedBound_TransNeigh:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_FixedBound_TransNeigh test_FixedBound_TransNeigh.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_FixedBound_TransNeigh $(BIN_DIR)

test_FixedBound_Trans:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_FixedBound_Trans test_FixedBound_Trans.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_FixedBound_Trans $(BIN_DIR)

test_FixedBound_Majority:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_FixedBound_Majority test_FixedBound_Majority.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_FixedBound_Majority $(BIN_DIR)

test_PeriodicBound_Majority:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_PeriodicBound_Majority test_PeriodicBound_Majority.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_PeriodicBound_Majority $(BIN_DIR)

test_PeriodicBound_Trans:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_PeriodicBound_Trans test_PeriodicBound_Trans.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_PeriodicBound_Trans $(BIN_DIR)

test_PeriodicBound_TransNeigh:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_PeriodicBound_TransNeigh test_PeriodicBound_TransNeigh.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_PeriodicBound_TransNeigh $(BIN_DIR)

test_NoBound_Majority:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_NoBound_Majority test_NoBound_Majority.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_NoBound_Majority $(BIN_DIR)

test_NoBound_Trans:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_NoBound_Trans test_NoBound_Trans.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_NoBound_Trans $(BIN_DIR)

test_NoBound_TransNeigh:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_NoBound_TransNeigh test_NoBound_TransNeigh.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_NoBound_TransNeigh $(BIN_DIR)

test_localized_init:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) test_localized_init test_localized_init.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv test_localized_init $(BIN_DIR)

# test_game_of_life:  $(INC_DIR)/myCA.h 
# 	$(CPP) $(CPPFLAGS2) test_game_of_life test_game_of_life.cpp \
# 	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
# 	mv test_game_of_life $(BIN_DIR)

all: $(EXECUTABLES)

cleanall: 
	cd $(BIN_DIR); rm $(EXECUTABLES)