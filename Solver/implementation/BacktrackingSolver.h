//
//  BacktrackingSolver.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_BACKTRACKING_SOLVER_H
#define TOAST_IMP_BACKTRACKING_SOLVER_H

#include "CellChecker.h"

#include "ISolver.h"

namespace toast { namespace imp
  {
    class BacktrackingSolver : public api::ISolver
    {
    public:
      BacktrackingSolver();
      ~BacktrackingSolver();
      
      virtual bool Solve(PTR<api::IGrid>& grid) override;
    };
  }
}

#endif //TOAST_IMP_BACKTRACKING_SOLVER_H
