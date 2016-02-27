//
//  Factory.cpp
//  Solver
//
//  Created by Tom Stainer on 26/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#include "Factory.h"

namespace toast { namespace factory
{
  
  const std::shared_ptr<api::ICell> Factory::CreateEmptyCell()
  {
    return std::make_shared<Cell>();
  }
  
  const std::shared_ptr<api::ICell> Factory::CreateValueCell(TNATURAL value)
  {
    const std::shared_ptr<api::ICell> cell = std::make_shared<Cell>();
    cell->SetValue(value);
    
    return cell;
  }
  
  const std::shared_ptr<api::IRow> Factory::CreateRow(int nrOfCells)
  {
    std::vector<std::shared_ptr<api::ICell>> cells(nrOfCells);
    for(int i=0;i<nrOfCells;++i)
    {
      cells[i] = CreateEmptyCell();
    }
    
    return std::make_shared<Row>(cells);
  }
  
  const std::shared_ptr<api::IBlock> Factory::CreateBlock(TNATURAL size)
  {
    std::vector<std::shared_ptr<api::IRow>> rows(size);
    for (int i=0;i<size;++i)
    {
      rows[i] = CreateRow(size);
    }
    
    return std::make_shared<Block>(rows);
  }
  
}
}

