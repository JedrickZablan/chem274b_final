// Description: # Chem 274B: Software Engineering Fundamentals for
//               Molecular Sciences
// Final project :  Design and C++ Implementation of General Purpose
//                 Cellular Automata Library. 
// Team members: Sheyda Nazarian, Yingyin Yu,Jedrick Regala Zablan 
// Date Created: 12/2/2023 


//    This file contains a C++ test program that tests functionality
//     of CA_setup functions. 
#include "myCA.h"
using namespace std;
#include <iostream>

int main()
{

    int err;
    vector<vector<int>> CA_1D; 
    vector<vector<int>> CA_2D;

    Cellular_Automata myCA_1D;
    Cellular_Automata myCA_2D;

    int dim1 = 100;
    int dim2 = 200;

    // set-up 1D CA
    err = myCA_1D.CA_setup_dimension(CA_1D, 1 , dim1);
    if (err==0)
    {
        std::cout << " 1D CA_setup_dimension succsessfull."<<std::endl;
    }
    else 
    {
        std::cout <<" 1D CA setup dimension error code is: " << err << std::endl;
    }

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

    //1D CA
    err = myCA_1D.CA_setup_neighbourhood(CA_1D, MOORE_NEIGH);
    if (err == 0)
    {
        std::cout << " 1D CA_setup_neighbourhood succsessfull."<<std::endl;
    }
    else 
    {
        std::cout <<" 1D CA_setup_neighbourhood error code is: " << err << std::endl;
    }

    //set-up boundry
    //2D
    err = myCA_2D.CA_setup_boundrytype(CA_2D, NO_BOUNDARY);
    if (err==0)
    {
        std::cout<< " 2D CA_setup_boundrytype successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 2D CA_setup_boundrytype error code is: " << err << std::endl;
    }

    //1D
    err = myCA_1D.CA_setup_boundrytype(CA_1D, PERIODIC_BOUNDARY);
    if (err==0)
    {
        std::cout<< " 1D CA_setup_boundrytype successfull." << std::endl;
    }
    else 
    {
        std::cout <<" 1D CA_setup_boundrytype error code is: " << err << std::endl;
    }
    
    return 0;
}