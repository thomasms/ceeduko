//
//  SolverFactory.hpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//
#ifndef TOAST_SOLVER_FACTORY_H
#define TOAST_SOLVER_FACTORY_H

#include <memory>
#include <vector>

#include "Types.h"

#include "IGrid.h"
#include "ISolver.h"

using namespace toast::utils;

namespace toast { namespace factory
  {
    class SolverFactory
    {
    public:
      static const PTR<api::ISolver> CreateBacktrackingSolver();
      
    };
    
  }
}
#endif //TOAST_SOLVER_FACTORY_H
