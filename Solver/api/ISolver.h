//
//  ISolver.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_ISOLVER_H
#define TOAST_API_ISOLVER_H

#include "Types.h"

#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for the solver
     *
     */
    class ISolver
    {
    public:
      virtual ~ISolver(){};
      
      /* @brief Solves the grid
       *
       * throws GeneralException when grid is not setup correctly
       * param[inout] grid The grid for which to solve
       * return True if solution found, false if no solution found
       */
      virtual bool Solve() = 0;
    };
    
  }
}

#endif //TOAST_API_ISOLVER_H
