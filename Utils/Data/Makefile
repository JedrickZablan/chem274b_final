# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Utils/Data

# Directory path to .txt data files
TST_LOCALIZED_INIT = Data_test_localized_init

# data to analyze
ANALYZE_DATA = analyze_localized_init

analyze_localized_init: 
	cd $(TST_LOCALIZED_INIT); python analyze.py

all: $(ANALYZE_DATA)

cleanall:
	cd $(TST_LOCALIZED_INIT); rm Data_test_localized_init/*.txt
	cd $(TST_LOCALIZED_INIT); rm Data_test_localized_init/*.png
