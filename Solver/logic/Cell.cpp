//
//  Cell.cpp
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#include "Cell.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    const TNATURAL Cell::DefaultValue = 0;
    
    Cell::Cell() : _value(DefaultValue)
    {
    }
    
    Cell::~Cell()
    {
    }
    
    void Cell::Draw(std::ofstream& writer) const
    {
      DrawTop(writer);
      DrawSide(writer);
      DrawSideWithValue(writer);
      DrawSide(writer);
      DrawBottom(writer);
    }
    
    void Cell::DrawTop(std::ofstream& writer) const
    {
      writer << std::setw(11) << "***********";
      writer << "\n";
    }
    
    void Cell::DrawSide(std::ofstream& writer) const
    {
      writer << std::setw(11) << "*         *";
      writer << "\n";
    }
    
    void Cell::DrawSideWithValue(std::ofstream& writer) const
    {
      writer << "*" << std::setw(5) << _value << std::setw(5) << "*";
      writer << "\n";
    }
    
    void Cell::DrawBottom(std::ofstream& writer) const
    {
      DrawTop(writer);
      writer << "\n";
    }
    
  }
}

