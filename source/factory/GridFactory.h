//
//  GridFactory.hpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//
#ifndef TOAST_GRID_FACTORY_H
#define TOAST_GRID_FACTORY_H

#include <memory>
#include <vector>

#include "Types.h"

#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace factory
  {
    class GridFactory
    {
    public:
      static const PTR<api::IGrid> CreateEmptySquareGrid(size_t size);
      
      static const PTR<api::IGrid> CreateEmptyGrid(size_t nr_of_rows, size_t nr_of_columns);
            
    };
    
  }
}
#endif //TOAST_GRID_FACTORY_H
