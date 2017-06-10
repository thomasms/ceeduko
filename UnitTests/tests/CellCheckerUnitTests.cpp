//
//  CellCheckerUnitTest.cpp
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include <memory>

#include "catch.hpp"

#include "UnitTestUtils.h"
#include "ITwoCaseTester.h"

#include "CellCheckerTester.h"

using namespace toast::api;
using namespace toast::imp;

namespace toast { namespace unittests {
  
  TEST_CASE( "Cell Checker Sunny", "[CellChecker]" ) {
    const auto grid = GridTestFactory::CreatePartialFilledSquareNineGrid();
    const size_t row_index = 8;
    const size_t column_index = 8;
    const TNATURAL test_value = 6;
    
    const PTR<ITwoCaseTester> tester = std::make_shared<CellCheckerTester>(grid, row_index, column_index, test_value );
    tester->ValidateSunny();
  }
  
  TEST_CASE( "Cell Checker Rainy", "[CellChecker]" ) {
    const auto grid = GridTestFactory::CreatePartialFilledSquareNineGrid();
    const size_t row_index = 8;
    const size_t column_index = 8;
    const TNATURAL test_value = 5;
    
    const PTR<ITwoCaseTester> tester = std::make_shared<CellCheckerTester>(grid, row_index, column_index, test_value );
    tester->ValidateRainy();
  }
  
  
  
}
}
