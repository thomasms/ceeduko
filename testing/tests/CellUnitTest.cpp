//
//  CellUnitTest.cpp
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include <memory>

#include "catch.hpp"

#include "ITester.h"

#include "CellTester.h"
#include "CellInvalidTester.h"

using namespace toast::api;
using namespace toast::imp;

namespace toast { namespace unittests {
  
  TEST_CASE( "Cell Default", "[ICell]" ) {
    const PTR<ITester> cell_tester = std::make_shared<CellTester>(nullptr, &ICell::GetValue, &ICell::SetValue, 4);
    cell_tester->InitialiseDefault();
    cell_tester->ValidateDefault();
  }
  
  TEST_CASE( "Cell Value", "[ICell]" ) {
    const PTR<ITester> cell_tester = std::make_shared<CellTester>(nullptr, &ICell::GetValue, &ICell::SetValue, 6);
    cell_tester->Initialise();
    cell_tester->Validate();
  }
  
  TEST_CASE( "Cell Value Using Function Call Operator", "[ICell]" ) {
    const PTR<ITester> cell_tester = std::make_shared<CellTester>(nullptr, &ICell::operator(), &ICell::SetValue, 6);
    cell_tester->Initialise();
    cell_tester->Validate();
  }
  
  TEST_CASE( "Cell Invalid Value", "[ICell]" ) {
    const PTR<ITester> cell_tester = std::make_shared<CellInvalidTester>(nullptr, &ICell::GetValue, &ICell::SetValue, 0,
                                                                         "Cell must have a positive value for defined values");
    cell_tester->Initialise();
    cell_tester->Validate();
  }
}
}
