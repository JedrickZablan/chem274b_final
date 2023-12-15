# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Application/Bin

# This makefile runs some tests. 

# Directory paths
APP_DATA_DIR = ../Data/


EXECUTABLES = run_cancer_cell_growth_VonNeuman run_cancer_cell_growth_Moore \
				run_cancer_cell_growth_prob_Moore run_cancer_cell_growth_prob_VonNeuman

run_cancer_cell_growth_VonNeuman: cancer_cell_growth_VonNeuman
	./cancer_cell_growth_VonNeuman
	rm -f ../Data/cancer_cell_growth_VonNeuman/*.txt
	rm -f ../Data/cancer_cell_growth_VonNeuman/*.png
	mv *.txt ../Data/cancer_cell_growth_VonNeuman

run_cancer_cell_growth_Moore: cancer_cell_growth_Moore
	./cancer_cell_growth_Moore
	rm -f ../Data/cancer_cell_growth_Moore/*.txt
	rm -f ../Data/cancer_cell_growth_Moore/*.png
	mv *.txt ../Data/cancer_cell_growth_Moore

run_cancer_cell_growth_prob_Moore: cancer_cell_growth_prob_Moore
	./cancer_cell_growth_prob_Moore
	rm -f ../Data/cancer_cell_growth_prob_Moore/*.txt
	rm -f ../Data/cancer_cell_growth_prob_Moore/*.png
	mv *.txt ../Data/cancer_cell_growth_prob_Moore

run_cancer_cell_growth_prob_VonNeuman: cancer_cell_growth_prob_VonNeuman
	./cancer_cell_growth_prob_VonNeuman
	rm -f ../Data/cancer_cell_growth_prob_VonNeuman/*.txt
	rm -f ../Data/cancer_cell_growth_prob_VonNeuman/*.png
	mv *.txt ../Data/cancer_cell_growth_prob_VonNeuman

all: $(EXECUTABLES)

	