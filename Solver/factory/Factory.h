//
//  Cell.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Cell_h
#define Solver_Cell_h

#include "Types.h"

#include "ICell.h"

using namespace toast::utils;

namespace toast { namespace logic
{
  class Cell : public api::ICell
  {
    public:
      Cell();    
      ~Cell();
    
      inline const TNATURAL GetValue() const
      {
        return _value;
      }
    
      inline void SetValue(const TNATURAL value)
      {
        _value = value;
      }
    
    private:
      TNATURAL _value;
  };

}
}
#endif
