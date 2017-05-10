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
const std::string filename = "//Users//tom//XCodeProjects//Solver//Solver//test.txt";

int main(int argc, const char * argv[])
{
  try{
//    size_t rows = 3;
//    size_t columns = 5;
//    auto grid = factory::GridFactory::CreateEmptyGrid(rows, columns);
//                                                    
//    // Set some test data
//    (*grid)(0,0)->SetValue(5);
//    (*grid)(1,0)->SetValue(2);
//    (*grid)(rows-2,columns-1)->SetValue(9);
//    
//    // write/read to file
//    PTR<api::ISerializable> serializable_object = std::dynamic_pointer_cast<api::ISerializable>(grid);
//    io::WriteToFile(filename, serializable_object);
//    grid->Clear();
    
    PTR<api::ISerializable> serializable_object = std::dynamic_pointer_cast<api::ISerializable>(factory::GridFactory::CreateEmptyGrid(0, 0));
    io::ReadFromFile(filename, serializable_object);
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
