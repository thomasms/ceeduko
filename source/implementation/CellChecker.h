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

#include "Definitions.h"
#include "Exceptions.h"
#include "Types.h"

#include "ICell.h"
#include "IGrid.h"

NAMESPACE_USING(toast::utils)

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(imp)

    class CellChecker
    {
    public:
      CellChecker(PTR<api::IGrid>& grid);
      ~CellChecker();
      
      bool IsOk(PTR<api::ICell>& cell, TNATURAL value) const;
      bool IsOk(size_t row_index, size_t column_index, TNATURAL value) const;
      
    private:
      bool IsInRow(size_t row_index, size_t column_index, TNATURAL value) const;
      bool IsInColumn(size_t row_index, size_t column_index, TNATURAL value) const;
      bool IsInSubGrid(size_t row_index, size_t column_index, TNATURAL value) const;
      std::pair<size_t,size_t> FindCellLocation(PTR<api::ICell>& cell) const;
      
      inline bool CheckCell(const PTR<api::ICell>& cell, TNATURAL value) const{
          return ((*cell) && (*cell)() == value );
      }
        
    private:
      PTR<api::IGrid>& _grid;
    };
    
NAMESPACE_END //imp
NAMESPACE_END //toast

#endif //TOAST_IMP_CELL_CHECKER_H
