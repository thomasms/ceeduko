//
//  SolverFactory.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "BacktrackingSolver.h"

#include "SolverFactory.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)
    
    // The brute force backtracking solver
    const PTR<api::ISolver> SolverFactory::CreateBacktrackingSolver(PTR<api::IGrid>& grid)
    {
      return std::make_shared<imp::BacktrackingSolver>(grid);
    }

NAMESPACE_END //factory
NAMESPACE_END //toast
