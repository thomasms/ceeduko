//
//  main.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include <iostream>

#include "ICell.h"
#include "IGrid.h"
#include "ISolver.h"
#include "ISerializable.h"
#include "GridFactory.h"
#include "SolverFactory.h"
#include "GeneralException.h"
#include "FileIO.h"

using namespace toast;
const std::string dir = "//Users//tom//XCodeProjects//Solver//Solver//";
const std::string ext = ".txt";
const std::string name = "9x9_unsolvable_board";
const std::string filename_unsolved = dir + name + ext;
const std::string filename_solved = dir + name + "_solved" + ext;

int main(int argc, const char * argv[])
{
  try{    
    // Read in the grid from file
    auto grid = factory::GridFactory::CreateEmptySquareGrid(0);
    PTR<api::ISerializable> serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
    io::ReadFromFile(filename_unsolved, serializable_object);
    
    // Validate the grid
    grid->Validate();
    
    // Create a solver
    auto solver = factory::SolverFactory::CreateBacktrackingSolver();
    if(solver->Solve(grid))
      std::cout << "Solution found!" << NEWLINE;
    else
      std::cout << "No solution found!" << NEWLINE;
    
    // Write the solved grid to file
    serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
    io::WriteToFile(filename_solved, serializable_object);
    
    // Write to std output
    std::cout << serializable_object << NEWLINE;
  }
  catch(GeneralException& ex)
  {
    std::cout << ex.what() << NEWLINE;
  }
  catch(std::exception& ex)
  {
    std::cout << ex.what() << NEWLINE;
  }
  catch(...)
  {
    std::cout << "Unknown error!" << NEWLINE;
  }
  return 0;
}
