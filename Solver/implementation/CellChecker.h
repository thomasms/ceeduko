//
//  CellChecker.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_CELL_CHECKER_H
#define TOAST_IMP_CELL_CHECKER_H

#include <vector>

#include "Types.h"

#include "ICell.h"
#include "IGrid.h"

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
      std::vector<TNATURAL> GetValidSet(size_t row_index, size_t column_index) const;
      std::vector<TNATURAL> GetRowSet(size_t row_index) const;
      std::vector<TNATURAL> GetColumnSet(size_t column_index) const;
      
    private:
      PTR<api::IGrid>& _grid;
    };
  }
}

#endif //TOAST_IMP_CELL_CHECKER_H
