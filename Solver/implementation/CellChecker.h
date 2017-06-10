//
//  CellChecker.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_CELL_CHECKER_H
#define TOAST_IMP_CELL_CHECKER_H

#include <cmath>
#include <vector>

#include "Types.h"

#include "ICell.h"
#include "IGrid.h"

#include "GridOperation.h"

using namespace toast::utils;

namespace toast { namespace imp
  {
    class CellChecker
    {
    public:
      CellChecker(PTR<api::IGrid>& grid);
      ~CellChecker();
      
      bool IsOk(size_t row_index, size_t column_index, TNATURAL value) const;
      
    private:
      bool IsInRow(size_t row_index, size_t column_index, TNATURAL value) const;
      bool IsInColumn(size_t row_index, size_t column_index, TNATURAL value) const;
      bool IsInSubGrid(size_t row_index, size_t column_index, TNATURAL value) const;
      bool CheckCell(PTR<api::ICell>& cell, TNATURAL value) const;
      
    private:
      PTR<api::IGrid>& _grid;
    };
  }
}

#endif //TOAST_IMP_CELL_CHECKER_H
