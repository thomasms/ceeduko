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
                 const std::function<TNATURAL(const api::ICell&)>& getter,
                 const std::function<void(api::ICell&, TNATURAL)>& setter,
                 TNATURAL value)
      :
      _cell(cell),
      _getter(getter),
      _setter(setter),
      _value(value)
      {
      }
      
      virtual ~CellTester()
      {
      }
      
      virtual void InitialiseDefault() override
      {
        REQUIRE(_cell == nullptr);
        _cell = factory::CellFactory::CreateEmptyCell();
        REQUIRE(_cell != nullptr);
      }
      
      virtual void Initialise() override
      {
        REQUIRE(_cell == nullptr);
        _cell = factory::CellFactory::CreateValueCell(_value);
        REQUIRE(_cell != nullptr);
      }
      
      virtual void ValidateDefault() override
      {
        REQUIRE(_cell != nullptr);
        REQUIRE(_cell->HasValue() == false);
        //validate cell data
        REQUIRE_NOTHROW(_cell->Validate());
      }
      
      virtual void Validate() override
      {
        REQUIRE(_cell != nullptr);
        
        //validate cell data
        REQUIRE_NOTHROW(_cell->Validate());
        
        // check getter
        REQUIRE(_getter(*_cell) == _value);
        REQUIRE(_cell->HasValue() == true);
        
        // clear cell
        REQUIRE_NOTHROW(_cell->Clear());
        REQUIRE(_cell->HasValue() == false);
        
        // and set value again
        _setter(*_cell,_value);
        REQUIRE(_getter(*_cell) == _value);
        REQUIRE(_cell->HasValue() == true);
      }
      
    protected:
      TNATURAL _value;
      PTR<api::ICell> _cell;
      std::function<TNATURAL(const api::ICell&)> _getter;
      std::function<void(api::ICell&,TNATURAL)> _setter;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_CELL_TESTER_H
