# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 

UTILS_DIR = Utils/ 
APP_UTILS_DIR = Application/Utils      
SRC_DIR = Source/
TST_DIR = Tests/
BIN_DIR = Bin/
APP_BIN_DIR = Application/Bin
APP_DIR = Application
UDATA_DIR = Utils/Data
APP_UDATA_DIR = Application/Utils/Data

all:
	cd $(SRC_DIR); make all
	cd $(APP_UTILS_DIR); make all
	cd $(TST_DIR); make all
	cd $(BIN_DIR); make all
	cd $(APP_BIN_DIR); make all

cleanall:	
	cd $(APP_DIR); make cleanall
	cd $(UTILS_DIR); make cleanall
	cd $(SRC_DIR); make cleanall
	cd $(TST_DIR); make cleanall
	
