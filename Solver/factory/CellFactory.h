//
//  Factory.h
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_CELL_FACTORY_H
#define TOAST_CELL_FACTORY_H

#include "Types.h"

#include "ICell.h"

using namespace toast::utils;

namespace toast { namespace factory
{
  class CellFactory
  {
  public:
    static const PTR<api::ICell> CreateEmptyCell();
    
    static const PTR<api::ICell> CreateValueCell(TNATURAL value);
    
    static const std::vector< PTR<api::ICell> > CreateEmptyCellRow(size_t nr_of_cells);
  };

}
}
#endif //TOAST_CELL_FACTORY_H
