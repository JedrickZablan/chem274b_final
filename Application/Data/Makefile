# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Utils/Data

# Directory path to .txt data files
MOORE = cancer_cell_growth_Moore
MOORE_PROB = cancer_cell_growth_prob_Moore
VONNEUMANN_PROB = cancer_cell_growth_prob_VonNeuman
VONNEUMANN = cancer_cell_growth_VonNeuman

# data to analyze
ANALYZE_DATA = analyze_moore analyze_moore_prob analyze_vonneumann analyze_vonneumann_prob

analyze_moore: 
	cd $(MOORE); python analyze.py

analyze_moore_prob:
	cd $(MOORE_PROB); python analyze.py

analyze_vonneumann:
	cd $(VONNEUMANN); python analyze.py

analyze_vonneumann_prob:
	cd $(VONNEUMANN_PROB); python analyze.py

all: $(ANALYZE_DATA)

