// Description: # Chem 274B: Software Engineering Fundamentals for
//               Molecular Sciences
// Final project :  Design and C++ Implementation of General Purpose
//                 Cellular Automata Library. 
// Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
// Date Created: 12/2/2023 

// This file contains C++ Object-Oriented implementation of the Cellular 
// Automata class. 
// The API (include) file is myCA.h

// myCA.h Contains the C++ Class definitions for our
//               basic data structures and flag.


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
using namespace std;


// function: Cellular_Automata::Cellular_Automata() constructor 
//           
//    input: no inputs
//   output: default constructor for the Cellular_Automata class
Cellular_Automata::Cellular_Automata()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

}

// function: Cellular_Automata::Cellular_Automata() default destructor 
//           releases the memory 
//    input: no inputs
//   output: 
Cellular_Automata::~Cellular_Automata()
{

}

// function: Cellular_Automata::CA_setup_dimension
//    input: A Cellular Automata object
//           dims: The number of dimensions
//           dim1: The size of the first dimension
//           dim2: The size of the second dimension 
//   output: CA_ERR_UNSUPPORTED_DIMENSION
//           CA_NO_ERR
int Cellular_Automata::CA_setup_dimension(vector<vector<int> >& CA, int dims, int dim1, int dim2)
{
    if (dims == 1) 
    {
        _dims = dims;
        // Setup for 1D Cellular Automata
        CA.resize(1); // Only one row
        CA[0].resize(dim1); // Set the size of the row
        _dim1 = dim1;
    } 
    else if (dims == 2) 
    {
        _dims = dims;
        // Setup for 2D Cellular Automata
        CA.resize(dim1);
        _dim1 = dim1;
        _dim2 = dim2;
        
        //iterate over each element of CA
        for (auto &row : CA) //range-based for loop- &row reference to each element
        {
            row.resize(dim2);
        }
        } else {
            // Unsupported dimension
            return CA_ERR_UNSUPPORTED_DIMENSION;
        }
        return CA_NO_ERR; // Success
}

// function: Cellular_Automata::CA_setup_neighbourhood
//    input: A Cellular Automata object
//           neighborhood type
//   output: CA_NO_ERR
//           CA_ERR_INVALID_NEIGHBOURHOOD
int Cellular_Automata::CA_setup_neighbourhood(vector<vector<int> >& CA, int neigh_type)
{
    // Check if the neighborhood type is valid
    if (neigh_type != VON_NEUMAN_NEIGH  && neigh_type != MOORE_NEIGH) {
        return CA_ERR_INVALID_NEIGHBOURHOOD;
    }
    _neigh_type = neigh_type;
    if (_neigh_type == VON_NEUMAN_NEIGH)
    {
        Cellular_Automata::setupVonNeumannNeighbourhood();
    }
    else if (_neigh_type == MOORE_NEIGH)
    {
        Cellular_Automata::setupMooreNeighbourhood();
    }
    return CA_NO_ERR; // Success
}

// function: Cellular_Automata::setupMooreNeighbourhood()
//   output: Sets up the neiborhood offset for Moore neighborhood
void Cellular_Automata::setupMooreNeighbourhood() {
    if (_dims == 2) {
        _neigh_Offsets = {{-1, -1}, {-1, 0}, {-1, 1},{0, -1}, {0, 1},{1, -1}, {1, 0}, {1, 1}};
    } else if (_dims == 1) {
        setup1DNeighbourhood();
    }
}

// function: Cellular_Automata::setupVonNeumannNeighbourhood()
//   output: Sets up the neiborhood offset for Von Neumann neighborhood
void Cellular_Automata::setupVonNeumannNeighbourhood() {
    if (_dims == 2) {
        _neigh_Offsets = {{-1, 0},{0, -1}, {0, 1},{1, 0}};
    } else if (_dims == 1) {
        setup1DNeighbourhood();
    }
}

// function: Cellular_Automata::setup1DNeighbourhood()
//   output: Sets up the neiborhood offset for 1 dimensional CA
void Cellular_Automata::setup1DNeighbourhood() {
    _neigh_Offsets = {{-1, 0}, {1, 0}}; // Left and right neighbors for 1D
}

// function: Cellular_Automata::CA_setup_boundrytype
//    input: A Cellular Automata object
//           boundry type
//   output: CA_NO_ERR
//           CA_ERR_INVALID_BOUNDRY
int Cellular_Automata::CA_setup_boundrytype(vector<vector<int> >& CA, int boundry_type, int radius)
{
    //check if the boundry type in valid 
    if ((boundry_type != NO_BOUNDARY) && (boundry_type != PERIODIC_BOUNDARY ) && (boundry_type !=FIXED_BOUNDARY))
    {
        return CA_ERR_INVALID_BOUNDRY; 
    }
    _boundry_type = boundry_type;
    _radius = radius;
    if (_radius !=1)
    {
        //update the neighborhood offset 
        Calculate_Neighborhood_Offsets(_radius); 
    }
    return CA_NO_ERR; // Success
}

// function: Cellular_Automata::Calculate_Neighborhood_Offsets
//    input: radius
//   output: updates _neigh_Offsets acording to user input radius
void Cellular_Automata::Calculate_Neighborhood_Offsets(int radius) 
{
    _neigh_Offsets.clear();

    if (_neigh_type == VON_NEUMAN_NEIGH) {
        for (int dx = -radius; dx <= radius; ++dx) {
            for (int dy = -radius; dy <= radius; ++dy) {
                if (abs(dx) + abs(dy) <= radius) {
                    _neigh_Offsets.push_back({dx, dy});
                }
            }
        }
    } else if (_neigh_type == MOORE_NEIGH) {
        for (int dx = -radius; dx <= radius; ++dx) {
            for (int dy = -radius; dy <= radius; ++dy) {
                if (max(abs(dx), abs(dy)) <= radius) {
                    _neigh_Offsets.push_back({dx, dy});
                }
            }
        }
    }

    // Remove the center cell (0,0) from the offsets if it exists
    _neigh_Offsets.erase(std::remove(_neigh_Offsets.begin(), _neigh_Offsets.end(), std::array<int, 2>{0, 0}), _neigh_Offsets.end());
}


// function: Cellular_Automata::CA_setup_cell_states
//    input: A Cellular Automata object
//           number of states
//   output: CA_NO_ERR
//           CA_ERR_INVALID_NSTATES
int Cellular_Automata::CA_setup_cell_states(vector<vector<int> >& CA, int nstates)
{
    if (nstates <= 0)  // Ensuring a positive number of states
    {
        return CA_ERR_INVALID_NSTATES;
    }
    _nstates = nstates; 
    return CA_NO_ERR; // Success
}

// function: Cellular_Automata::CA_init_cond
//    input: A Cellular Automata object
//           initial state 
//           probability of initial state
//   output: CA_NO_ERR
//           CA_ERR_INVALID_NSTATES
int Cellular_Automata::CA_init_cond(vector<vector<int> >& CA, int x_state, double prob)
{
    // Validate the probability
    if (prob < 0.0 || prob > 1.0)
    {
        return CA_ERR_INVALID_PROBABILITY;
    }

    // Iterate over the CA grid
    for (int i = 0; i < _dim1; ++i)
    {
        for (int j = 0; j < _dim2; ++j)
        {
            // For fixed boundary, set edge cells to 0
            if (_boundry_type == FIXED_BOUNDARY && isEdgeCell(i, j))
            {
                CA[i][j] = 0;
            }
            else // Assign initial state based on probability for non-edge cells
            {
                // Generate a random number between 0 and 1
                double rand_prob = static_cast<double>(rand()) / RAND_MAX;

                // Assign the initial state considering the user input probability
                if (rand_prob <= prob)
                {
                    CA[i][j] = x_state;
                }
                else
                {
                    CA[i][j] = 0; // Assign zero to the rest of the cells
                }
            }
        }
    }
    return CA_NO_ERR; // Success
}




// function: Cellular_Automata::CA_init_cond_rewrite
//    input: A Cellular Automata object
//           initial state 
//           probability of initial state
//   output: CA_NO_ERR
//           
int Cellular_Automata::CA_init_cond_rewrite(vector<vector<int> >& CA, int x_state, double prob)
{
    // Validate the probability
    if (prob < 0.0 || prob > 1.0)
    {
        return CA_ERR_INVALID_PROBABILITY;
    }

    // Iterate over the CA grid
    for (int i = 0; i < _dim1; ++i)
    {
        for (int j = 0; j < _dim2; ++j)
        {
            // Skip this cell if it's not in state 0
            if (CA[i][j] != 0)
            {
                continue;
            }

            // For fixed boundary, set edge cells to 0
            if (_boundry_type == FIXED_BOUNDARY && isEdgeCell(i, j))
            {
                CA[i][j] = 0;
            }
            else // Assign new state based on probability for cells in state 0
            {
                // Generate a random number between 0 and 1
                double rand_prob = static_cast<double>(rand()) / RAND_MAX;

                // Assign the new state considering the user input probability
                if (rand_prob <= prob)
                {
                    CA[i][j] = x_state;
                }
                // Note: Cells already in state 0 do not need to be set again
            }
        }
    }

    return CA_NO_ERR; // Success
}

// function: Cellular_Automata::CA_init_cond_rewrite
//    input: A Cellular Automata object
//           initial state 
//           probability of initial state
//   output: CA_NO_ERR
// 
int Cellular_Automata:: CA_setup_rule(vector<vector<int> >& CA,std::vector<int> rule_types)
{
    for (int rule : rule_types) {
        if (rule != MAJORITY_RULE && 
            rule != STRAIGHT_CONDITIONAL_TRANSITION_RULE && 
            rule != CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR){
            return CA_ERR_UNSUPPORTED_RULE_TYPE;
        }
    }

    _rule_types = rule_types;
    return CA_NO_ERR;
    
}


// function: Cellular_Automata::applyMajorityRule
//    input: A Cellular Automata object
//   output: 
// 
// Apply the majority rule to a single cell and return the new state
int Cellular_Automata::apply_Majority_Rule(const vector<vector<int>>& CA, int x, int y) {
    vector<int> stateCount(_nstates, 0);
    stateCount[CA[x][y]]++; // Include the cell's own state

    // Count the frequency of each state in the neighborhood
    for (const auto& offset : _neigh_Offsets) {
        int ni = x + offset[0];
        int nj = y + offset[1];

        // Use getCellState with boundary condition
        int neighborState = getCellState(CA, ni, nj, _boundry_type);

        // Increment state count if valid
        if (neighborState >= 0 && neighborState < _nstates) {
            stateCount[neighborState]++;
        }
    }

    // Determine the most frequent state
    int mostFrequentState = distance(stateCount.begin(), max_element(stateCount.begin(), stateCount.end()));

    return mostFrequentState;
}



// function: Cellular_Automata::applyIncrementalTransitionRule
//   input: A reference to a Cellular Automata grid (2D vector) and the maximum state n
//   output: modifies the CA grid directly
//           No return 

int Cellular_Automata::apply_Transition_Rule(const vector<vector<int>>& CA, int x, int y) {
    int currentState = CA[x][y];

    // Check for edge cells if boundary type is FIXED_BOUNDARY
    if (_boundry_type == FIXED_BOUNDARY && isEdgeCell(x, y)) {
        return currentState;  // No change for edge cells
    }

    // Increment the state by one, unless it's already at the maximum state n
    if (currentState < _nstates-1) {
        return currentState + 1;
    } else {
        return currentState;  // State remains the same if it's already at max
    }
}

// function: Cellular_Automata::apply_Neighbor_Transition_Rule
//   input: A reference to a Cellular Automata grid (2D vector) and the maximum state n
//   output: modifies the CA grid directly
//           No return 
int Cellular_Automata::apply_Neighbor_Transition_Rule(const vector<vector<int>>& CA, int x, int y) {
    int currentState = CA[x][y];

    // Iterate over neighbors
    for (const auto& offset : _neigh_Offsets) {
        int ni = x + offset[0];
        int nj = y + offset[1];

        // Check for edge cells if boundary type is FIXED_BOUNDARY and do not change state
        if (_boundry_type == FIXED_BOUNDARY && isEdgeCell(x, y)) {
            return currentState; // No change for edge cells
        }

        // Apply boundary conditions
        if (_boundry_type == PERIODIC_BOUNDARY) {
            ni = (ni + _dim1) % _dim1;
            nj = (nj + _dim2) % _dim2;
        } else if (_boundry_type == FIXED_BOUNDARY && (ni < 0 || ni >= _dim1 || nj < 0 || nj >= _dim2)) {
            continue; // Skip if outside the grid for fixed boundary
        }

        // Skip if outside the grid for no boundary or fixed boundary
        else if (_boundry_type == NO_BOUNDARY || _boundry_type == FIXED_BOUNDARY) {
            if (ni < 0 || ni >= _dim1 || nj < 0 || nj >= _dim2) {
                continue; 
            }
        }

        // Check if any neighbor has a state one higher than the current state
        if (currentState < _nstates-1 && CA[ni][nj] == currentState + 1) {
            return currentState + 1; // Update state if conditions met and not at max state
        }
    }

    return currentState; // Return the current state if no change is needed
}





// function: Cellular_Automata::applyMajorityRule
//    input: A Cellular Automata object
//   output: state of cell x * y
int Cellular_Automata::getCellState(const vector<vector<int>>& CA, int x, int y)
{
    // Implement boundary conditions here. For now, let's assume fixed boundary.
    if (x < 0 || x >= _dim1 || y < 0 || y >= _dim2)
        return CA_ERR_OUT_OF_RANGE_CELL; // Return a default state if the cell is outside the grid.
    
    return CA[x][y];
}


// function: Cellular_Automata::CA_setup_rule_wprob
//    input: A Cellular Automata object
//           rule type
//           probability 
//   output: state of cell x * y
int Cellular_Automata::CA_setup_rule_wprob(vector<vector<int> >& CA,std::vector<int> rule_type, double prob)
{
    if (prob < 0.0 || prob > 1.0) {
        return CA_ERR_INVALID_PROBABILITY;
    }

    // Check each rule type in the vector
    for (int rule : rule_type) {
        if (rule != MAJORITY_RULE && 
            rule != STRAIGHT_CONDITIONAL_TRANSITION_RULE && 
            rule != CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR) {
            return CA_ERR_UNSUPPORTED_RULE_TYPE;
        }
    }

    // Set up the rule types with associated probability
    _rule_types = rule_type;
    _rule_prob = prob;

    return CA_NO_ERR;
}


int Cellular_Automata::getCellState(const vector<vector<int>>& CA, int x, int y, int boundaryCondition)
{
    int _dimX = CA.size();       // Number of rows
    int _dimY = CA[0].size();    // Number of columns

    // Handle Periodic Boundary Condition
    if (boundaryCondition == PERIODIC_BOUNDARY) {
        x = (x + _dimX) % _dimX;
        y = (y + _dimY) % _dimY;
        return CA[x][y];
    }

    // Handle Fixed or Walled Boundary Condition
    if (boundaryCondition == FIXED_BOUNDARY) {
        if (x < 0 || x >= _dimX || y < 0 || y >= _dimY)
            return 0; // Assume the fixed state is 0
        else
            return CA[x][y];
    }

    // Handle No Boundary Condition
    if (boundaryCondition == NO_BOUNDARY) {
        if (x < 0 || x >= _dimX || y < 0 || y >= _dimY)
            return CA_NO_NEIGHBOR; // Return a special value indicating no neighbor
        else
            return CA[x][y];
    }

    return CA_ERR_INVALID_BOUNDRY; // Default case, if no boundary condition is matched
}

bool Cellular_Automata::isEdgeCell(int i, int j) {
    return i == 0 || i == _dim1 - 1 || j == 0 || j == _dim2 - 1;
}


// function: Cellular_Automata::applyMajorityRuleWithProb
//    input: A Cellular Automata object, x and y of cell
//   output: applies majority rule considering probability
// 
// Apply the majority rule to a single cell and return the new state
int Cellular_Automata::apply_Majority_Rule_Prob(vector<vector<int>>& CA, int x, int y) {
    double rand_prob = static_cast<double>(rand()) / RAND_MAX;
    //std::cout <<"rand prob majority here" << rand_prob<< std::endl;
    if (rand_prob <= _rule_prob) {
        vector<int> stateCount(_nstates, 0);
        stateCount[CA[x][y]]++; // Include the cell's own state

        // Count the frequency of each state in the neighborhood
        for (const auto& offset : _neigh_Offsets) {
            int ni = x + offset[0];
            int nj = y + offset[1];
            int neighborState = getCellState(CA, ni, nj, _boundry_type);

            if (neighborState >= 0 && neighborState < _nstates) {
                stateCount[neighborState]++;
            }
        }

        // Determine the most frequent state
        return distance(stateCount.begin(), max_element(stateCount.begin(), stateCount.end()));
    }
    return CA[x][y]; // No change if probability condition is not met
}

// function: Cellular_Automata::applyIncrementalTransitionRuleWithProb
//   input: A reference to a Cellular Automata grid (2D vector), x and y of the cell
//   output: returns new state of cell considering Transition Rule with probablity
//           
int Cellular_Automata::apply_Transition_Rule_Prob(vector<vector<int>>& CA, int x, int y) {
    double rand_prob = static_cast<double>(rand()) / RAND_MAX;
    if (rand_prob <= _rule_prob) {
        int currentState = CA[x][y];
        if (_boundry_type == FIXED_BOUNDARY && isEdgeCell(x, y)) {
            return currentState;
        }

        if (currentState < _nstates - 1) {
            return currentState + 1;
        }
    }
    return CA[x][y]; // No change if probability condition is not met
}


// function: Cellular_Automata::applyIncrementalNeighborTransitionRuleWithProb
//   input: A reference to a Cellular Automata grid (2D vector), x and y of cell
//   output: returns new state of cell considering Neighbor Transition rule with probability

int Cellular_Automata::apply_Neighbor_Transition_Rule_Prob(vector<vector<int>>& CA, int x, int y) {
    double rand_prob = static_cast<double>(rand()) / RAND_MAX;
    //std::cout <<"rand prob transitional here" << rand_prob<< std::endl;
    if (rand_prob <= _rule_prob) {
        int currentState = CA[x][y];

        for (const auto& offset : _neigh_Offsets) {
            int ni = x + offset[0];
            int nj = y + offset[1];

            if (_boundry_type == PERIODIC_BOUNDARY) {
                ni = (ni + _dim1) % _dim1;
                nj = (nj + _dim2) % _dim2;
            } else if (_boundry_type == FIXED_BOUNDARY && (ni < 0 || ni >= _dim1 || nj < 0 || nj >= _dim2)) {
                continue;
            }

            if (currentState < _nstates - 1 && CA[ni][nj] == currentState + 1) {
                return currentState + 1;
            }
        }
    }
    return CA[x][y]; // No change if probability condition is not met
}


// function: Cellular_Automata::computeStep
//    input: number of timesteps
//   output: applies rules with probability to the CA grid based on the timestep
void Cellular_Automata::CA_compute_step_prob(vector<vector<int>>& CA, int timesteps) {
    for (int t = 0; t < timesteps; ++t) {
        vector<vector<int>> newCA = CA; // Create a copy for the new state

        for (int i = 0; i < _dim1; ++i) {
            for (int j = 0; j < _dim2; ++j) {
                int currentState = CA[i][j];
                int ruleType = _rule_types[currentState];
                
                // Apply the rule based on the ruleType
                if (ruleType == MAJORITY_RULE) {
                    newCA[i][j] = apply_Majority_Rule_Prob(CA, i, j);
                } else if (ruleType == STRAIGHT_CONDITIONAL_TRANSITION_RULE) {
                    newCA[i][j] = apply_Transition_Rule_Prob(CA, i, j);
                } else if (ruleType == CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR) {
                    newCA[i][j] = apply_Neighbor_Transition_Rule_Prob(CA, i, j);
                } 
            }
        }
        // Update the CA grid with the new states after applying rules
        CA = newCA;
    }
}


// function: Cellular_Automata::computeStep
//    input: number of timesteps
//   output: applies rules to the CA grid based on the timestep
void Cellular_Automata::CA_compute_step(vector<vector<int>>& CA, int timesteps) {
    for (int t = 0; t < timesteps; ++t) {
        vector<vector<int>> newCA = CA; // Create a copy for the new state

        for (int i = 0; i < _dim1; ++i) {
            for (int j = 0; j < _dim2; ++j) {
                int currentState = CA[i][j];
                int ruleType = _rule_types[currentState];

                // Apply the rule based on the ruleType
                if (ruleType == MAJORITY_RULE) {
                    newCA[i][j] = apply_Majority_Rule(CA, i, j);
                } else if (ruleType == STRAIGHT_CONDITIONAL_TRANSITION_RULE) {
                    newCA[i][j] = apply_Transition_Rule(CA, i, j);
                } else if (ruleType == CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR) {
                    newCA[i][j] = apply_Neighbor_Transition_Rule(CA, i, j);
                } 

            }
        }
        // Update the CA grid with the new states after applying rules
        CA = newCA;
    }
}

//function: Cellular_Automata::compute_with_report
//input:
//  CA: 2D vector cellular automaton
//  timesteps: number of timesteps
//  report_step: the interval that each step is reported
//output:
//  out stream to a txt file that reports the CA
void Cellular_Automata::compute_with_report(vector<vector<int>>& CA, int timesteps, int report_step) {
    for (int t = 0; t < timesteps; ++t) {
        // Check if it's time to report the current state
        if (t % report_step == 0) {
            std::string prob_report_filename = "CA_state_report_" + std::to_string(t) + ".txt";
            std::ofstream prob_report_file(prob_report_filename);

            if (!prob_report_file.is_open()) {
                cerr << "Failed to open the report file: " << prob_report_filename << endl;
                continue; // Skip this report and continue to the next
            }

            prob_report_file << "At time step: " << t << endl;

            // Print the states of each cell to txt file
            for (const auto& row : CA) {
                for (int cell : row) {
                    prob_report_file << cell << " ";
                }
                prob_report_file << endl;
            }

            prob_report_file.close(); // Close the txt file
        }

        // Perform the computation step after reporting
        CA_compute_step(CA, 1);
    }
}

//function: Cellular_Automata::compute_with_prob_report
//input:
//  CA: 2D vector cellular automaton reference
//  timesteps: number of timesteps
//  report_step: the interval that each step is reported
//output:
//  out stream to a txt file that reports the CA
void Cellular_Automata::compute_with_prob_report(vector<vector<int>>& CA, int timesteps, int report_step) {
    for (int t = 0; t < timesteps; ++t) {
        // Report state of CA at the current time step
        if (t % report_step == 0 || t == 0) { 
            std::string prob_report_filename = "CA_state_report_" + std::to_string(t) + ".txt";
            std::ofstream prob_report_file(prob_report_filename);

            if (!prob_report_file.is_open()) {
                cerr << "Failed to open the report file: " << prob_report_filename << endl;
                continue; // Skip this report and continue to the next
            }

            prob_report_file << "At time step: " << t << endl; 

            // Print the states of each cell to the txt file
            for (const auto& row : CA) {
                for (int cell : row) {
                    prob_report_file << cell << " ";
                }
                prob_report_file << endl;
            }

            prob_report_file.close(); // Close the txt file
        }

        // Perform the computation step after reporting
        CA_compute_step_prob(CA, 1);
    }
}

// function: Cellular_Automata::CA_init_cond_localized
//    input: A Cellular Automata object reference, x_state, and percent_state
//   output: CA_NO_ERR on success, or an appropriate error code
int Cellular_Automata::CA_init_cond_localized(vector<vector<int> >& CA, int x_state, double percent_state)
{

    int total_cells = _dim1 * _dim2;
    int target_state_count = static_cast<int>(round(percent_state * total_cells / 100.0));

    int central_i = _dim1 / 2;
    int central_j = _dim2 / 2;

    // Initialize all cells to state 0
    for (auto& row : CA) {
        fill(row.begin(), row.end(), 0);
    }

    // Set the central cell to x_state
    CA[central_i][central_j] = x_state;
    int state_count = 1;

    std::list<std::pair<int, int>> available_neighbors;

    // Add initial neighbors of the central cell
    for (const auto& offset : _neigh_Offsets) {
        int ni = central_i + offset[0];
        int nj = central_j + offset[1];

        if (ni >= 0 && ni < _dim1 && nj >= 0 && nj < _dim2) {
            available_neighbors.emplace_back(ni, nj);
        }
    }

    // Randomly select neighbors and set them to x_state until the target count is reached
    while (state_count < target_state_count && !available_neighbors.empty()) {
        auto it = available_neighbors.begin();
        std::advance(it, rand() % available_neighbors.size());
        auto cell = *it;
        available_neighbors.erase(it);

        if (CA[cell.first][cell.second] == 0) {
            CA[cell.first][cell.second] = x_state;
            state_count++;


            // Add new neighbors of this cell
            for (const auto& offset : _neigh_Offsets) {
                int ni = cell.first + offset[0];
                int nj = cell.second + offset[1];

                if (ni >= 0 && ni < _dim1 && nj >= 0 && nj < _dim2 && CA[ni][nj] == 0 
                    && find(available_neighbors.begin(), available_neighbors.end(), make_pair(ni, nj)) == available_neighbors.end()) {
                    available_neighbors.emplace_back(ni, nj);
                }
            }
        }
    }

    return CA_NO_ERR;
}
    

bool Cellular_Automata::allNeighborsAreXState(const vector<vector<int>>& CA, int x, int y, int x_state)
{
    for (const auto& offset : _neigh_Offsets)
    {
        int ni = x + offset[0];
        int nj = y + offset[1];

        // Apply boundary conditions
        if (_boundry_type == PERIODIC_BOUNDARY) {
            ni = (ni + _dim1) % _dim1;
            nj = (nj + _dim2) % _dim2;
        } else if (_boundry_type == FIXED_BOUNDARY && (ni < 0 || ni >= _dim1 || nj < 0 || nj >= _dim2)) {
            continue; // Skip if outside the grid for fixed boundary
        }

        // If any neighbor is not in state x_state, return false
        if (CA[ni][nj] != x_state) {
            return false;
        }
    }
    return true; // All neighbors are in state x_state
}

