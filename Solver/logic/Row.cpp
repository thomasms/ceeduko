//
//  Row.cpp
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#include "Row.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    
    Row::Row(const std::vector<std::shared_ptr<api::ICell>>& cells) : _cells(cells)
    {
    }
    
    Row::~Row()
    {
    }
    
    void Row::Draw(std::ofstream& writer) const
    {
      // Draw tops first
      for(auto cell: _cells)
      {
        writer << "********";
      }
      writer << "*\n";
      
      // Draw side
      for(auto cell: _cells)
      {
        writer << "*       ";
      }
      writer << "*\n";
      
      // Draw side with value
      for(auto cell: _cells)
      {
        if(cell->GetValue() == Cell::DefaultValue)
          writer << "*       ";
        else
          writer << "*   "<< cell->GetValue() << "   ";
      }
      writer << "*\n";
      
      // Draw side
      for(auto cell: _cells)
      {
        writer << "*       ";
      }
      writer << "*\n";
      
    }
    
  }
}

