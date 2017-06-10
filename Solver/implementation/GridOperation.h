//
//  GridOperation.h
//  Solver
//
//  Created by Thomas Stainer on 10/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_GRID_OPERATION_H
#define TOAST_IMP_GRID_OPERATION_H

#include "Types.h"

#include "ICell.h"
#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace imp
  {
    class GridOperation
    {
    public:
      GridOperation(PTR<api::IGrid>& grid)
      :
      _grid(grid)
      {
      }
      
      // Performs operation on each cell in the grid
      void operator()(std::function<void(size_t r, size_t c)> func)
      {
        for(size_t r=0;r<_grid->GetNrOfRows();++r){
          for(size_t c=0;c<_grid->GetNrOfColumns();++c){
            func(r,c);
          }
        }
      }
      
    private:
      PTR<api::IGrid> _grid;
    };
    
  }
}

#endif //TOAST_IMP_GRID_OPERATION_H
