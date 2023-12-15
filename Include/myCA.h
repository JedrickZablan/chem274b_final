// README for Include
// Chem 274B: Software Engineering Fundamentals for
//               Molecular Sciences
// Final project :  Design and C++ Implementation of General Purpose
//                 Cellular Automata Library. 
// Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
// Date Created: 12/2/2023 

//
//  myCA.h contains the necessary include files and 
//             C++ Class declarations for Cellular Automata. 

#pragma once    // Ensures that this file is only included once
                // during compilation
using namespace std;
#include "myCA.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <queue>    // Include for std::queue
#include <list>
#include <iterator>

// List of FLAGS for neighborhood type:
#define VON_NEUMAN_NEIGH  1
#define MOORE_NEIGH 2

// List of FLAGS for boundry type:
#define NO_BOUNDARY 3
#define PERIODIC_BOUNDARY 4
#define FIXED_BOUNDARY 5

//LIST OF FLAGS FR RULES
#define MAJORITY_RULE 6
#define STRAIGHT_CONDITIONAL_TRANSITION_RULE 7
#define CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR 8
#define  GAME_OF_LIFE 9

class Cellular_Automata
{

    public:
        Cellular_Automata();
        ~Cellular_Automata();
        int CA_setup_dimension(vector<vector<int> >& CA, int dims, int dim1, int dim2=0);
        int CA_setup_neighbourhood(vector<vector<int> >& CA, int neigh_type);
        int CA_setup_boundrytype(vector<vector<int> >& CA, int boundry_type, int radius=1);
        int CA_setup_cell_states(vector<vector<int> >& CA, int nstates);
        int CA_init_cond(vector<vector<int> >& CA, int x_state, double prob);
        int CA_init_cond_rewrite(vector<vector<int> >& CA, int x_state, double prob);
        int CA_setup_rule(vector<vector<int> >& CA,std::vector<int> rule_types);
        int CA_setup_rule_wprob(vector<vector<int> >& CA,std::vector<int> rule_type, double prob);
        void CA_compute_step_prob(vector<vector<int>>& CA, int timesteps);
        void CA_compute_step(vector<vector<int>>& CA, int timesteps);
        void compute_with_report(vector<vector<int>>& CA, int timesteps, int report_step); 
        void compute_with_prob_report(vector<vector<int>>& CA, int timesteps, int report_step);
        int CA_init_cond_localized(vector<vector<int> >& CA, int x_state, double percent_state);

    private:
        int _dims; //1D: dims=1 or 2D: dims=2 
        int _dim1;
        int _dim2;
        int _radius;
        int _nstates;
        double _rule_prob;
        std::vector<int> _rule_types;
        int _neigh_type; // VON_NEUMAN or MOORE
        int _boundry_type; //NO boundry, periodic or fixed
        std::vector<std::array<int, 2>> _neigh_Offsets; // Stores offsets for neighbors

        void Calculate_Neighborhood_Offsets(int radius);
        int apply_Majority_Rule(const vector<vector<int>>& CA, int x, int y);
        int apply_Majority_Rule_Prob(vector<vector<int>>& CA, int x, int y);
        int apply_Transition_Rule(const vector<vector<int>>& CA, int x, int y);
        int apply_Transition_Rule_Prob(vector<vector<int>>& CA, int x, int y);
        int apply_Neighbor_Transition_Rule(const vector<vector<int>>& CA, int x, int y);
        int apply_Neighbor_Transition_Rule_Prob(vector<vector<int>>& CA, int x, int y);
        int getCellState(const vector<vector<int>>& CA, int x, int y);
        int getCellState(const vector<vector<int>>& CA, int x, int y, int boundaryCondition);
        bool isEdgeCell(int i, int j);
        void setup1DNeighbourhood();
        void setupVonNeumannNeighbourhood();
        void setupMooreNeighbourhood();  
        bool allNeighborsAreXState(const vector<vector<int>>& CA, int x, int y, int x_state);
};

// Cellular Automata ERROR CODES
#define CA_NO_ERR 0 
#define CA_ERR_UNSUPPORTED_DIMENSION -1
#define CA_ERR_INVALID_NEIGHBOURHOOD -2
#define CA_ERR_INVALID_BOUNDRY -3
#define CA_ERR_INVALID_NSTATES -4
#define CA_ERR_INVALID_PROBABILITY -5
#define CA_ERR_UNSUPPORTED_RULE_TYPE -6
#define CA_ERR_OUT_OF_RANGE_CELL -7
#define CA_NO_NEIGHBOR -8