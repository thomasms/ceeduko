//
//  BacktrackingSolver.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_BACKTRACKING_SOLVER_H
#define TOAST_IMP_BACKTRACKING_SOLVER_H

#include <cmath>
#include <vector>

#include "CellChecker.h"
#include "GeneralException.h"

#include "ISolver.h"

namespace toast { namespace imp
  {
    class BacktrackingSolver : public api::ISolver
    {
    public:
      BacktrackingSolver(PTR<api::IGrid>& grid);
      ~BacktrackingSolver();
      
      // Returns false if no solution exists
      //
      // Throws GeneralException if the grid dimensions are incompatible
      virtual bool Solve() override;
      
    private:
      bool VerifyGrid() const;
      bool Loop();
      bool Initialise();
      
      // throws exception on incorrect grid
      void CheckGridDimensions() const;
      
    private:
      std::vector< PTR<api::ICell> > _empty_cells;
      PTR<api::IGrid>& _grid;
      PTR<CellChecker> _cell_checker;
    };
  }
}

#endif //TOAST_IMP_BACKTRACKING_SOLVER_H
