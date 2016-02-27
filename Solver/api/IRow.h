//
//  IRow.h
//  Solver
//
//  Created by Tom Stainer on 26/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_IRow_h
#define Solver_IRow_h

#include <memory>

#include "IDrawable.h"
#include "ICell.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    class IRow : public IDrawable
    {
    public:
      virtual ~IRow(){};
      virtual const std::shared_ptr<ICell>& GetCell(int index) const = 0;
      
      virtual const int GetNumberOfCells() const = 0;
    protected:
      IRow(){};
      
    };
    
  }
}

#endif
