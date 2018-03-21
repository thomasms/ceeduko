//
//  CellFactory.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Cell.h"

#include "CellFactory.h"

namespace toast { namespace factory
{
  
  // Empty Cell
  const PTR<api::ICell> CellFactory::CreateEmptyCell()
  {
      return std::make_shared<imp::Cell>();
  }
  
  // Valued Cell
  const PTR<api::ICell> CellFactory::CreateValueCell(TNATURAL value)
  {
      return std::make_shared<imp::Cell>(value);
  }
  
  // Empty Cell Row
  const std::vector< PTR<api::ICell> > CellFactory::CreateEmptyCellRow(size_t nr_of_cells){
    std::vector< PTR<api::ICell>> row;
    
    for(size_t i=0; i<nr_of_cells; ++i){
      row.push_back(CreateEmptyCell());
    }
    
    return row;
  }
  
}
}

