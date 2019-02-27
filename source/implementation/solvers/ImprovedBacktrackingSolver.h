//
//  BacktrackingSolver.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_IMPROVED_BACKTRACKING_SOLVER_H
#define TOAST_IMP_IMPROVED_BACKTRACKING_SOLVER_H

#include <cmath>
#include <vector>

#include "Definitions.h"
#include "Exceptions.h"
#include "CellChecker.h"

#include "ISolver.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(imp)

    class ImprovedBacktrackingSolver : public api::ISolver
    {
    public:

      ImprovedBacktrackingSolver(PTR<api::IGrid>& grid) : _grid(grid)
      {
        // object for checking if a cell value is ok in that grid location
        _cell_checker = std::make_shared<CellChecker>(_grid);
      }
      
      ~ImprovedBacktrackingSolver()
      {
      }
      
      // Returns false if no solution exists
      //
      // Throws GeneralException if the grid dimensions are incompatible
      bool Solve() override;
      
    private:
      bool VerifyGrid() const;
      bool FindNext();
      bool Initialise();
      
      // throws exception on incorrect grid
      void CheckGridDimensions() const;

    private:
      std::vector<std::pair<size_t, size_t> > _empty_cell_r_c;
      std::vector< PTR<api::ICell> > _empty_cells;
      PTR<api::IGrid>& _grid;
      PTR<CellChecker> _cell_checker;
    };

NAMESPACE_END //imp
NAMESPACE_END //toast

#endif //TOAST_IMP_IMPROVED_BACKTRACKING_SOLVER_H
