//
//  SolverFactory.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "solvers/BacktrackingSolver.h"
#include "solvers/ImprovedBacktrackingSolver.h"

#include "SolverFactory.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)
    
    // The brute force backtracking solver
    const PTR<api::ISolver> CreateBacktrackingSolver(PTR<api::IGrid>& grid)
    {
      return std::make_shared<imp::BacktrackingSolver>(grid);
    }
    
    // The brute force backtracking solver - slighty faster
    const PTR<api::ISolver> CreateImprovedBacktrackingSolver(PTR<api::IGrid>& grid)
    {
      return std::make_shared<imp::ImprovedBacktrackingSolver>(grid);
    }

NAMESPACE_END //factory
NAMESPACE_END //toast
