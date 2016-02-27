//
//  Factory.h
//  Solver
//
//  Created by Tom Stainer on 26/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Factory_h
#define Solver_Factory_h

#include <memory>
#include <vector>

#include "Types.h"

#include "Cell.h"
#include "Row.h"
#include "Block.h"

#include "ICell.h"
#include "IRow.h"
#include "IBlock.h"

using namespace toast::utils;
using namespace toast::logic;

namespace toast { namespace factory
{
  class Factory
  {
  public:
    static const std::shared_ptr<api::ICell> CreateEmptyCell();
    
    static const std::shared_ptr<api::ICell> CreateValueCell(TNATURAL value);
    
    static const std::shared_ptr<api::IRow> CreateRow(TNATURAL nrOfCells);
    
    static const std::shared_ptr<api::IBlock> CreateBlock(TNATURAL size);
  };

}
}
#endif
