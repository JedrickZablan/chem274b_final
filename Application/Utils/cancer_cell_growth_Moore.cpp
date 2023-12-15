// Description: # Chem 274B: Software Engineering Fundamentals for
//               Molecular Sciences
// Final project :  Design and C++ Implementation of General Purpose
//                 Cellular Automata Library. 
// Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
// Date Created: 12/2/2023 


//    This file contains a C++ program that simulates cancer cell growth.
//    simulation parameters:
//      1000 x 1000 grid size 
//      Neighborhood: MOORE_NEIGH
//      States: 0 healthy cells, 1 cancer cells
//      Rulles: 
//      healthy cells to cancer cells:CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR, 
//      cancer cells to healthy cells: MAJORITY_RULE

#include "myCA.h"
using namespace std;
#include <iostream>

int main()
{

    int err;
    vector<vector<int>> CA_2D;

    Cellular_Automata myCA_2D;

    int dim1 = 1000;
    int dim2 = 1000;


    // set-up 2D CA for cancer cell growth application 
    err = myCA_2D.CA_setup_dimension(CA_2D, 2 , dim1, dim2 );
    if (err==0)
    {
        std::cout << " 2D CA_setup_dimension succsessfull."<<std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_dimension error code is: " << err << std::endl;
    }

    // set-up neighborhood 
    //2D CA
    err = myCA_2D.CA_setup_neighbourhood(CA_2D, MOORE_NEIGH);
    if (err == 0)
    {
        std::cout << " 2D CA_setup_neighbourhood succsessfull."<<std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_neighbourhood error code is: " << err << std::endl;
    }

    
    //set-up boundry
    //2D
    err = myCA_2D.CA_setup_boundrytype(CA_2D, FIXED_BOUNDARY, 3);
    if (err==0)
    {
        std::cout<< " 2D CA_setup_boundrytype successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_boundrytype error code is: " << err << std::endl;
    }

    //set-up cell states
    err = myCA_2D.CA_setup_cell_states(CA_2D, 2);
    //0 is healthy cells
    //1 is cancerous cells

    if (err==0)
    {
        std::cout<< " 2D CA_setup_cell_states successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_cell_states error code is: " << err << std::endl;
    }
    
    //set-up initial condition
    err = myCA_2D.CA_init_cond_localized(CA_2D, 1, 0.1);
    if (err==0)
    {
        std::cout<< " 2D CA_init_cond successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_init_cond error code is: " << err << std::endl;
    }

    //set-up rule types

    std::vector<int> rule_types = {CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR, MAJORITY_RULE};
    err = myCA_2D.CA_setup_rule(CA_2D,rule_types);
    if (err==0)
    {
        std::cout<< " 2D CA_setup_rule successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_rule error code is: " << err << std::endl;
    }

    myCA_2D.compute_with_report(CA_2D, 100, 5); 
    
    return 0;
}