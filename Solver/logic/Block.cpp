//
//  Block.cpp
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#include "Block.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    Block::Block(const std::vector<std::shared_ptr<api::IRow>>& rows) : _rows(rows)
    {
    }
    
    Block::~Block()
    {
    }
    
    void Block::SetValue(int n,int m, TNATURAL value)
    {
      _rows[n]->GetCell(m)->SetValue(value);
    }
    
    void Block::Draw(std::ofstream& writer) const
    {
      for(auto row: _rows)
        row->Draw(writer);
      
      // Draw bottom
      for(auto row: _rows)
      {
        writer << "********";
      }
      writer << "*\n";
    }
    
  }
}

