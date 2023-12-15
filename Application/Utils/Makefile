# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Application


# GNU C++ Compiler
CPP         = g++      

# other compiler flags -g debug, -c create a library object
CPPFLAGS    = -O0 -o
CPPFLAGS2	= -std=c++11 -O0 -o
CPPFLAGSANITIZER = -std=c++11 -O0  -g -fsanitize=address -o
CPPFLAGVALGRIND = -std=c++11 -O0  -g -o

# The directory where all object files are going to be moved after creation
BIN_DIR     = ../Bin
INC_DIR     = ../../Include
LIB_DIR     = ../../Lib
APP_BIN_DIR     = ../Bin

# The next line contains the list of object files created by this Makefile.
EXECUTABLES = cancer_cell_growth_VonNeuman cancer_cell_growth_Moore \
				cancer_cell_growth_prob_Moore cancer_cell_growth_prob_VonNeuman


cancer_cell_growth_VonNeuman:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) cancer_cell_growth_VonNeuman \
	cancer_cell_growth_VonNeuman.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv cancer_cell_growth_VonNeuman $(APP_BIN_DIR)

cancer_cell_growth_Moore:  $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) cancer_cell_growth_Moore \
	cancer_cell_growth_Moore.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv cancer_cell_growth_Moore $(APP_BIN_DIR)

cancer_cell_growth_prob_Moore: $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) cancer_cell_growth_prob_Moore \
	cancer_cell_growth_prob_Moore.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv cancer_cell_growth_prob_Moore $(APP_BIN_DIR)

cancer_cell_growth_prob_VonNeuman: $(INC_DIR)/myCA.h 
	$(CPP) $(CPPFLAGS2) cancer_cell_growth_prob_VonNeuman \
	cancer_cell_growth_prob_VonNeuman.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lmyCA 
	mv cancer_cell_growth_prob_VonNeuman $(APP_BIN_DIR)

all: $(EXECUTABLES)

cleanall:
	cd $(APP_BIN_DIR); rm $(EXECUTABLES)