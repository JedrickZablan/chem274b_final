# Description: # Chem 274B: Software Engineering Fundamentals for
#               Molecular Sciences
# Final project :  Design and C++ Implementation of General Purpose
#                 Cellular Automata Library. 
# Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
# Date Created: 12/1/2023 
# Path: ./Bin

# This makefile runs some tests. 


EXECUTABLES = run_test_CA_setup run_test_FixedBound_TransNeigh run_test_FixedBound_Trans \
				run_test_FixedBound_Majority run_test_PeriodicBound_Majority \
				run_test_PeriodicBound_Trans run_test_PeriodicBound_TransNeigh \
				run_test_NoBound_Majority run_test_NoBound_Trans \
				run_test_NoBound_TransNeigh run_test_localized_init 


run_test_CA_setup: test_CA_setup
	./test_CA_setup

run_test_FixedBound_TransNeigh: test_FixedBound_TransNeigh
	./test_FixedBound_TransNeigh

run_test_FixedBound_Trans: test_FixedBound_Trans
	./test_FixedBound_Trans

run_test_FixedBound_Majority: test_FixedBound_Majority
	./test_FixedBound_Majority

run_test_PeriodicBound_Majority: test_PeriodicBound_Majority
	./test_PeriodicBound_Majority

run_test_PeriodicBound_Trans: test_PeriodicBound_Trans
	./test_PeriodicBound_Trans

run_test_PeriodicBound_TransNeigh: test_PeriodicBound_TransNeigh
	./test_PeriodicBound_TransNeigh

run_test_NoBound_Majority: test_NoBound_Majority
	./test_NoBound_Majority

run_test_NoBound_Trans: test_NoBound_Trans
	./test_NoBound_Trans

run_test_NoBound_TransNeigh: test_NoBound_TransNeigh
	./test_NoBound_TransNeigh

run_test_localized_init: test_localized_init
	
	./test_localized_init
	rm -f ../Utils/Data/Data_test_localized_init/*.txt
	rm -f ../Utils/Data/Data_test_localized_init/*.png
	mv *.txt ../Utils/Data/Data_test_localized_init
	
# run_test_game_of_life: test_game_of_life
	
# 	./test_game_of_life
# 	rm -f ../Utils/Data/Data_test_game_of_life/*.txt
# 	rm -f ../Utils/Data/Data_test_game_of_life/*.png
# 	mv *.txt ../Utils/Data/Data_test_game_of_life

all: $(EXECUTABLES)

