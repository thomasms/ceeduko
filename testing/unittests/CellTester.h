//
//  CellTester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_CELL_TESTER_H
#define TOAST_UNIT_TESTS_CELL_TESTER_H

#include "catch.hpp"

#include "ICell.h"
#include "Cell.h"
#include "CellFactory.h"

#include "ITester.h"

using namespace toast::utils;

namespace toast { namespace unittests
  {
    class CellTester : public ITester
    {
    public:
      CellTester(const PTR<api::ICell>& cell,
                 TNATURAL value)
      :
      _cell(cell),
      _value(value)
      {
      }
      
      virtual ~CellTester()
      {
      }
      
      virtual void InitialiseDefault() override
      {
        REQUIRE(_cell == nullptr);
        _cell = factory::CreateEmptyCell();
        REQUIRE(_cell != nullptr);
      }
      
      virtual void Initialise() override
      {
        REQUIRE(_cell == nullptr);
        _cell = factory::CreateValueCell(_value);
        REQUIRE(_cell != nullptr);
      }
      
      virtual void ValidateDefault() override
      {
        REQUIRE(_cell != nullptr);
        REQUIRE((*_cell) == false);
        //validate cell data
        REQUIRE_NOTHROW(_cell->Validate());
      }
      
      virtual void Validate() override
      {
        REQUIRE(_cell != nullptr);
        
        //validate cell data
        REQUIRE_NOTHROW(_cell->Validate());
        
        // check getter
        REQUIRE((*_cell)() == _value);
        REQUIRE((*_cell) == true);
        
        // clear cell
        REQUIRE_NOTHROW(_cell->Clear());
        REQUIRE((*_cell) == false);
        
        // and set value again
        (*_cell)(_value);
        REQUIRE((*_cell)() == _value);
        REQUIRE((*_cell) == true);
      }
      
    protected:
      PTR<api::ICell> _cell;
      TNATURAL _value;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_CELL_TESTER_H
