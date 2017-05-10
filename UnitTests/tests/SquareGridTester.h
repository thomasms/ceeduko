//
//  SquareGridTester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_SQUARE_GRID_TESTER_H
#define TOAST_UNIT_TESTS_SQUARE_GRID_TESTER_H

#include <memory>

#include "catch.hpp"

#include "ICell.h"
#include "IGrid.h"
#include "Grid.h"
#include "GridFactory.h"

#include "CellTester.h"
#include "GeneralGridTester.h"

using namespace toast::api;
using namespace toast::utils;

namespace toast { namespace unittests
  {
    class SquareGridTester : public GeneralGridTester
    {
    public:
      SquareGridTester(size_t size, TNATURAL value)
      :
      GeneralGridTester(size,size,value)
      {
      }
      
      ~SquareGridTester()
      {
      }
      
      void Initialise() override
      {
        GeneralGridTester::Initialise();
        REQUIRE(_grid->GetNrOfRows() == _grid->GetNrOfColumns());
      }
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_SQUARE_GRID_TESTER_H
