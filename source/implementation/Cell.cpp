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
    Cell::Cell()
    {
      Clear();
    }
    
    Cell::~Cell()
    {
    }
    
    void Cell::Validate() const
    {
      if(HasValue() && GetValue() <= 0)
        throw GeneralException("Cell must have a positive value for defined values");
    }
    
    void Cell::Deserialize(std::istream& is)
    {
      char c;
      TNATURAL value{};
      bool found = false;
      bool is_empty = false;
      
      // read until value is found
      while(is.get(c))
      {
        if(isdigit(c))
        {
          value = atoi(&c);
          found = true;
          is_empty = false;
          break;
        }
        else if(c == EMPTYCELL)
        {
          found = true;
          is_empty = true;
          break;
        }
        else
        {
          continue;
        }
      }
      
      if(found)
      {
        SetValue(value);
        if(is_empty)
          Clear();
      }
    }
    
    void Cell::Serialize(std::ostream& os) const
    {
      if(HasValue())
        os << GetValue();
      else
        os << EMPTYCELL;
    }
    
  }
}
