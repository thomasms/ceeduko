//
//  Cell.cpp
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Cell.h"

namespace toast { namespace imp
{
    Cell::Cell() : _value(k_unset_value)
    {
    }

    Cell::Cell(TNATURAL value) : _value(value)
    {
    }
    
    Cell::~Cell()
    {
    }

    void Cell::Validate() const
    {
      if((*this) && (*this)() <= 0)
        throw CellValidationException("Cell must have a positive value for defined values");
    }
  }
}
