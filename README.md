# Chem 274B: Software Engineering Fundamentals for Molecular Sciences
# Final Project:  Design and C++ Implementation of General Purpose Cellular Automata Library. 
# Team Members: Sheyda Nazarian, Yingyin Yu, Jedrick Regala Zablan 
# Date Created: 12/1/2023 

# Project Description

This repository contains a comprehensive C++ library for Cellular Automata (CA) simulations, developed as part of the Chem 274B course. This group project showcases best practices in software engineering by designing and implementing a reusable CA library, a demonstration application using the library, and detailed analyses of the application outputs. My group successfully created an application that simulates the growth of cancer cells in tissue. The cancer starts from the center of the matrix and spreads outward to other cells using a simple model based on the Von Neumann neighborhood. This model does not account for tissue density, cell properties, or real-life cell-cell interactions. All source codes, documentation, and examples illustrating the library's capabilities are included. Additionally, the repository contains a PDF with a reflective analysis of the software development process, highlighting collaboration in cross-functional teams, algorithmic performance, and lessons learned. 

# Directory Guide
This directory is the root directory of this project.

LIST OF SUBDIRECTORIES IN THIS DIRECTORY:

- Application/ : This subdirectory contains our cancer call growth application

- Bin/ : This subdirectory contains all the executable program (test program)
		
- Include/ : This directory contains all the APIs in the form of  
        include header files (myCA.h)

- Lib/ : This subdirectory contains all library object files (.a)
		
- Source/ : This directory contains all the source code with the
        functionality implemented in C++ for this project
		
- Tests/: Test programs used to test the functionalities implemented in
        the project
		
- Utils/: Contains all the source files that implement utilities
        
LIST OF FILES IN THIS DIRECTORY:

- README: (this file) 

- Makefile: Makefile commands to compile C++ programs in the root directory.

- FinalProject_Assessment.pdf: Responses for Part 2 and Part 3 of final project

