//
//  main.cpp
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "Factory.h"

#include "ICell.h"
#include "IRow.h"
#include "IBlock.h"

using namespace toast;

int main(int argc, const char * argv[])
{
  auto block = factory::Factory::CreateBlock(9);
  
  // Some test values - the trival solution
  int counter = 0;
  TNATURAL value;
  for(int n=0;n<block->GetNumberOfRows();++n)
  {
    for(int m=0;m<block->GetNumberOfColumns();m++)
    {
      value = (m+1+(n*3)+counter)%9;
      if(value==0)value =9;
      
      block->SetValue(n, m,value);
    }
    if((n+1)%3==0) counter++;
  }
  
  std::ofstream writer("test.io");
  block->Draw(writer);
  
  writer.close();
  return 0;
}
