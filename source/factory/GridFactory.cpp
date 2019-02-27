//
//  GridFactory.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Grid.h"

#include "GridFactory.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)
    
    // Empty Square Grid
    const PTR<api::IGrid> CreateEmptySquareGrid(size_t size)
    {
      return std::make_shared<imp::Grid>(size,size);
    }
    
    // Empty Rectangluar Grid
    const PTR<api::IGrid> CreateEmptyGrid(size_t nr_of_rows, size_t nr_of_columns)
    {
      return std::make_shared<imp::Grid>(nr_of_rows,nr_of_columns);
    }

NAMESPACE_END //factory
NAMESPACE_END //toast
