//
//  SquareGrid.h
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_GRID_H
#define TOAST_IMP_GRID_H

#include <assert.h>
#include <algorithm>
#include <cmath>
#include <vector>

#include "Defs.h"
#include "Types.h"
#include "GeneralException.h"

#include "CellFactory.h"
#include "CellChecker.h"

#include "ICell.h"
#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace imp
{
    class Grid : public api::IGrid
    {
    public:
        Grid(size_t nr_of_rows, size_t nr_of_columns);
        ~Grid();
      
        void Operation(std::function<void(size_t row, size_t column)> func) const override;
        void Validate() const override;
        const PTR<api::ICell>& GetCell(size_t row, size_t column) const override;
        
        inline const PTR<api::ICell>& operator()(size_t row, size_t column) const override
        {
            return GetCell(row, column);
        }
        
        inline void Clear() override
        {
            auto func = [&](size_t r, size_t c){
                (*this)(r,c)->Clear();
            };
            Operation(func);
        }
            
        inline size_t GetNrOfRows() const override
        {
            return _cells.size();
        }
            
        inline size_t GetNrOfColumns() const override
        {
            size_t nr_of_columns = 0;
            if(GetNrOfRows() >0){
                nr_of_columns = _cells[0].size();
            }
            return nr_of_columns;
        }
      
    private:
      void CreateGrid(size_t nr_of_rows, size_t nr_of_columns);
      TNATURAL GetMaxValue() const;
      
    private:
      std::vector< std::vector< PTR<api::ICell> > > _cells;
        
    };
    
  }
}
#endif //TOAST_IMP_GRID_H
