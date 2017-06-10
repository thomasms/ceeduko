//
//  GridUnitTests.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//
#include "catch.hpp"

#include "Grid.h"
#include "GridFactory.h"
#include "SquareGridTester.h"
#include "GeneralGridTester.h"

using namespace toast::imp;

namespace toast { namespace unittests {
  
  TEST_CASE( "Grid Square Default", "[IGrid]" ) {
    const PTR<ITester> tester = std::make_shared<SquareGridTester>(4,4);
    tester->InitialiseDefault();
    tester->ValidateDefault();
  }
  
  TEST_CASE( "Grid Square", "[IGrid]" ) {
    const PTR<ITester> tester = std::make_shared<SquareGridTester>(9,1);
    tester->Initialise();
    tester->Validate();
  }
  
  // Currently no support for rectangular grids
  /*
  TEST_CASE( "Grid General Default", "[IGrid]" ) {
    const PTR<ITester> tester = std::make_shared<GeneralGridTester>(9,3,5);
    tester->InitialiseDefault();
    tester->ValidateDefault();
  }
  
  TEST_CASE( "Grid General", "[IGrid]" ) {
    const PTR<ITester> tester = std::make_shared<GeneralGridTester>(78,99,345);
    tester->Initialise();
    tester->Validate();
  }
  */
}
}
