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
  
  TEST_CASE( "Cell Checker Sunny Empty 9X9", "[CellChecker]" ) {
    const auto grid = GridTestFactory::CreateEmptySquareNineGrid();
    
    std::vector<PTR<ITwoCaseTester>> testers;
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 1, 2, 5 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 4, 5, 8 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 1, 2, 2 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 1, 2, 4 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 7, 5 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 6, 4, 5 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 9 ));
    
    for(auto& tester: testers)
      tester->ValidateSunny();
  }
  
  TEST_CASE( "Cell Checker Sunny Partial 9X9", "[CellChecker]" ) {
    const auto grid = GridTestFactory::CreatePartialFilledSquareNineGrid();
    
    std::vector<PTR<ITwoCaseTester>> testers;
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 1 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 2 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 4 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 6 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 9 ));
    
    for(auto& tester: testers)
      tester->ValidateSunny();
  }
  
  TEST_CASE( "Cell Checker Rainy Partial 9X9", "[CellChecker]" ) {
    const auto grid = GridTestFactory::CreatePartialFilledSquareNineGrid();
    
    std::vector<PTR<ITwoCaseTester>> testers;
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 3 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 5 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 7 ));
    testers.push_back(std::make_shared<CellCheckerTester>(grid, 8, 8, 8 ));
    
    for(auto& tester: testers)
      tester->ValidateRainy();
  }
  
  
  
}
}
