//
//  Block.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Block_h
#define Solver_Block_h

#include <vector>

#include "Types.h"
#include "Cell.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    class Block
    {
    public:
      Block(const std::vector<Cell>& row);
      ~Block();
      
    private:
      std::vector<Cell> rows;
    };
    
  }
}

#endif
