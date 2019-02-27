//
//  Factory.h
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_CELL_FACTORY_H
#define TOAST_CELL_FACTORY_H

#include "Definitions.h"
#include "Types.h"

#include "ICell.h"

NAMESPACE_USING(toast::utils)

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)

  const PTR<api::ICell> CreateEmptyCell();
  
  const PTR<api::ICell> CreateValueCell(TNATURAL value);
  
  const std::vector< PTR<api::ICell> > CreateEmptyCellRow(size_t nr_of_cells);

NAMESPACE_END //factory
NAMESPACE_END //toast

#endif //TOAST_CELL_FACTORY_H
