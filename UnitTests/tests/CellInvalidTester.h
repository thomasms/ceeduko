//
//  CellInvalidTester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_CELL_INVALID_TESTER_H
#define TOAST_UNIT_TESTS_CELL_INVALID_TESTER_H

#include <string>

#include "catch.hpp"

#include "Assertions.h"
#include "GeneralException.h"

#include "CellTester.h"

using namespace toast::utils;

namespace toast { namespace unittests
  {
    class CellInvalidTester : public CellTester
    {
    public:
      CellInvalidTester(const PTR<api::ICell>& cell,
                        const std::function<TNATURAL(const api::ICell&)>& getter,
                        const std::function<void(api::ICell&, TNATURAL)>& setter,
                        TNATURAL value,
                        std::string exception_msg)
      :
      CellTester(cell, getter, setter, value),
      _exception_msg(exception_msg)
      {
      }
      
      virtual ~CellInvalidTester()
      {
      }
      
      virtual void Validate() override
      {
        REQUIRE_NOTHROW(_cell != nullptr);
        
        // check getter
        REQUIRE_NOTHROW(_getter(*_cell) == _value);
        REQUIRE_NOTHROW(_cell->HasValue() == true);
        
        //validate cell data
        std::function<void()> validate_func = std::bind(&api::ICell::Validate, _cell);
        AssertExceptionMsg<void(),utils::GeneralException>(validate_func, _exception_msg);
      }
    private:
      std::string _exception_msg;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_CELL_INVALID_TESTER_H
