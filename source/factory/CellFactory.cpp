//
//  CellFactory.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Cell.h"

#include "CellFactory.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(factory)
  
  // Empty Cell
  const PTR<api::ICell> CreateEmptyCell()
  {
      return std::make_shared<imp::Cell>();
  }
  
  // Valued Cell
  const PTR<api::ICell> CreateValueCell(TNATURAL value)
  {
      return std::make_shared<imp::Cell>(value);
  }
  
  // Empty Cell Row
  const std::vector< PTR<api::ICell> > CreateEmptyCellRow(size_t nr_of_cells){
    std::vector< PTR<api::ICell>> row;
    
    for(size_t i=0; i<nr_of_cells; ++i){
      row.push_back(CreateEmptyCell());
    }
    
    return row;
  }

NAMESPACE_END //factory
NAMESPACE_END //toast

