//
//  ICell.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_ICell_h
#define Solver_ICell_h

#include "Types.h"

#include "IDrawable.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    class ICell : public IDrawable
    {
    public:
      virtual ~ICell(){};
      virtual const TNATURAL GetValue() const = 0;
      virtual void SetValue(const TNATURAL value) = 0;
      
    protected:
      ICell(){};
      
    };
    
  }
}

#endif
