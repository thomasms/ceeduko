//
//  UnitTestUtils.hpp
//  Solver
//
//  Created by Thomas Stainer on 10/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_UTILS_H
#define TOAST_UNIT_TESTS_UTILS_H

#include <string>

#include "catch.hpp"

#include "IGrid.h"

namespace toast { namespace unittests
  {    
    class GridTestFactory
    {
    public:
      static const PTR<api::IGrid> CreatePartialFilledSquareNineGrid();
    };
  }
}
#endif //TOAST_UNIT_TESTS_UTILS_H
