// Description: # Chem 274B: Software Engineering Fundamentals for
//               Molecular Sciences
// Final project :  Design and C++ Implementation of General Purpose
//                 Cellular Automata Library. 
// Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
// Date Created: 12/2/2023 


//    This file contains a C++ test program that tests functionality
//     of CA_setup functions for 2D CA. 
#include "myCA.h"
using namespace std;
#include <iostream>

int main()
{

    int err;
    vector<vector<int>> CA_2D;

    Cellular_Automata myCA_1D;
    Cellular_Automata myCA_2D;

    int dim1 = 5;
    int dim2 = 5;


    // set-up 2D CA
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
    err = myCA_2D.CA_setup_neighbourhood(CA_2D, VON_NEUMAN_NEIGH);
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
    err = myCA_2D.CA_setup_boundrytype(CA_2D, NO_BOUNDARY , 1);
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
    if (err==0)
    {
        std::cout<< " 2D CA_setup_cell_states successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_cell_states error code is: " << err << std::endl;
    }
    
    //set-up initial condition
    err = myCA_2D.CA_init_cond(CA_2D, 1, 0.3);
    if (err==0)
    {
        std::cout<< " 2D CA_init_cond successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_init_cond error code is: " << err << std::endl;
    }

    //set-up rule types

    std::vector<int> rule_types = {CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR, CONDITIONAL_TRANSITION_RULE_ON_NEIGHBOR};
    err = myCA_2D.CA_setup_rule(CA_2D,rule_types);
    if (err==0)
    {
        std::cout<< " 2D CA_setup_rule successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_rule error code is: " << err << std::endl;
    }

    // Print the CA matrix
    std::cout << "2D CA Matrix at t=0:" << std::endl;
    for (int i = 0; i < dim1; ++i)
    {
        for (int j = 0; j < dim2; ++j)
        {
            std::cout << CA_2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    myCA_2D.CA_compute_step(CA_2D, 1); 

    //  Print the CA matrix
    std::cout << "2D CA Matrix at t=1:" << std::endl;
    for (int i = 0; i < dim1; ++i)
    {
        for (int j = 0; j < dim2; ++j)
        {
            std::cout << CA_2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}