//
//  SolverFactory.hpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//
#ifndef TOAST_SOLVER_FACTORY_H
#define TOAST_SOLVER_FACTORY_H

#include "Definitions.h"
#include "Types.h"

#include "IGrid.h"
#include "ISolver.h"

NAMESPACE_USING(toast::utils)

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)

    const PTR<api::ISolver> CreateBacktrackingSolver(PTR<api::IGrid>& grid);
    const PTR<api::ISolver> CreateImprovedBacktrackingSolver(PTR<api::IGrid>& grid);
       
NAMESPACE_END //factory
NAMESPACE_END //toast

#endif //TOAST_SOLVER_FACTORY_H
