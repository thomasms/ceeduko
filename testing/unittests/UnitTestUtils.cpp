//
//  UnitTestUtils.cpp
//  Solver
//
//  Created by Thomas Stainer on 10/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "UnitTestUtils.h"

#include "GridFactory.h"

namespace toast { namespace unittests
  {
    
    /*
     
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     * * * * * * * * *
     
     */
    const PTR<api::IGrid> GridTestFactory::CreateEmptySquareNineGrid()
    {
      return factory::CreateEmptySquareGrid(9);
    }
    
    /*
     
     5 * * * * 1 * * *
     * * * * * * * * *
     4 * * * * * * * *
     * * * 2 * * * * 5
     * * * * * * 6 * 7
     * 7 * * * 9 * * *
     * * 8 * * * * * *
     * * * * * * * 8 *
     * * 3 * * * * * *
     
     */    
    const PTR<api::IGrid> GridTestFactory::CreatePartialFilledSquareNineGrid()
    {
      auto grid = factory::CreateEmptySquareGrid(9);
      (*(*grid)(0,0))(5);
      (*(*grid)(0,4))(1);
      (*(*grid)(2,0))(4);
      (*(*grid)(3,3))(2);
      (*(*grid)(3,8))(5);
      (*(*grid)(4,6))(6);
      (*(*grid)(4,8))(7);
      (*(*grid)(5,1))(7);
      (*(*grid)(5,5))(9);
      (*(*grid)(6,2))(8);
      (*(*grid)(7,7))(8);
      (*(*grid)(8,2))(3);
      return grid;
    }
    
    
  }
}
