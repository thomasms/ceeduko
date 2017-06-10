//
//  BacktrackingSolver.cpp
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "BacktrackingSolver.h"

namespace toast { namespace imp
  {
    BacktrackingSolver::BacktrackingSolver()
    {
    }
    
    BacktrackingSolver::~BacktrackingSolver()
    {
    }
    
    bool BacktrackingSolver::Solve(PTR<api::IGrid>& grid)
    {
      CellChecker checker(grid);
      
      
      return false;
    }
    
  }
}
