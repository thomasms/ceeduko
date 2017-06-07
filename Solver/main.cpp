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
#include "ISerializable.h"
#include "GridFactory.h"
#include "GeneralException.h"
#include "FileIO.h"

using namespace toast;
const std::string filename_unsolved = "//Users//tom//XCodeProjects//Solver//Solver//test.txt";
const std::string filename_solved = "//Users//tom//XCodeProjects//Solver//Solver//test_solved.txt";

int main(int argc, const char * argv[])
{
  try{
      // Create a test file
//    size_t size = 9;
//    auto grid = factory::GridFactory::CreateEmptySquareGrid(size);
//                                                    
//    // Set some test data
//    (*grid)(0,0)->SetValue(5);
//    (*grid)(1,0)->SetValue(2);
//    (*grid)(7,5)->SetValue(9);
//    (*grid)(4,8)->SetValue(5);
//    
//    // write/read to file
//    PTR<api::ISerializable> serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
//    io::WriteToFile(filename_unsolved, serializable_object);
//    grid->Clear();
    
    // Read in the grid from file
    auto grid = factory::GridFactory::CreateEmptySquareGrid(0);
    PTR<api::ISerializable> serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
    io::ReadFromFile(filename_unsolved, serializable_object);
    
    // Validate the grid
    grid->Validate();
    
    // Create a solver
    // ToDo: PTR<api::ISolver> solver = factory::SolverFactory::CreateBruteForce(grid); solver->Run(); 
    
    // Write the solved grid to file
    serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
    io::WriteToFile(filename_solved, serializable_object);
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
