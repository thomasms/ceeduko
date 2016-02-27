//
//  IBlock.h
//  Solver
//
//  Created by Tom Stainer on 26/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_IBlock_h
#define Solver_IBlock_h

#include <memory>
#include <vector>

#include "IDrawable.h"
#include "IRow.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    class IBlock : public IDrawable
    {
    public:
      virtual ~IBlock(){};
      virtual const std::vector<std::shared_ptr<IRow>>& GetRows() const = 0;
      
      virtual const int GetNumberOfRows() const = 0;
      virtual const int GetNumberOfColumns() const = 0;
      
      /**
       *@brief Set the value at the nth row at the mth column
       *@param[in] n The row index
       *@param[in] m The column index
       *@param[in] value The value to set
       */
      virtual void SetValue(int n,int m, TNATURAL value) = 0;
      
    protected:
      IBlock(){};
      
    };
    
  }
}

#endif
