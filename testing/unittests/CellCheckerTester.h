//
//  CellCheckerTester.h
//  Solver
//
//  Created by Thomas Stainer on 10/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H
#define TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H

#include "catch.hpp"

#include "Types.h"

#include "IGrid.h"
#include "CellChecker.h"
#include "GridOperation.h"

#include "ITester.h"

using namespace toast::utils;

namespace toast { namespace unittests
  {
    class CellCheckerTester : public ITwoCaseTester
    {
    public:
      CellCheckerTester(const PTR<api::IGrid>& grid,
                        size_t row_index,
                        size_t column_index,
                        TNATURAL value)
      :
      _grid(grid),
      _row_index(row_index),
      _column_index(column_index),
      _value(value)
      {
      }
      
      virtual ~CellCheckerTester()
      {
      }
      
      virtual void ValidateSunny() override
      {
        ValidateGrid();
        REQUIRE(imp::CellChecker(_grid).IsOk(_row_index, _column_index, _value) == true);
        
        // also try with cell method
        auto cell = (*_grid)(_row_index,_column_index);
        REQUIRE(imp::CellChecker(_grid).IsOk(cell, _value) == true);
      }
      
      virtual void ValidateRainy() override
      {
        ValidateGrid();
        REQUIRE(imp::CellChecker(_grid).IsOk(_row_index, _column_index, _value) == false);
        
        // also try with cell method
        auto cell = (*_grid)(_row_index,_column_index);
        REQUIRE(imp::CellChecker(_grid).IsOk(cell, _value) == false);
      }
      
    private:
      void ValidateGrid()
      {
        REQUIRE(_grid != nullptr);
        REQUIRE_NOTHROW(_grid->Validate());
        
        // Check that the grid has been correctly setup - i.e. check existing values are ok.
        imp::CellChecker checker(_grid);
        auto func = [&](size_t r, size_t c){
          auto cell = (*_grid)(r,c);
          REQUIRE(checker.IsOk(r,c,(*cell)()) == true);
        };
        
        (imp::GridOperation(_grid))(func);
      }
      
    private:
      PTR<api::IGrid> _grid;
      size_t _row_index;
      size_t _column_index;
      TNATURAL _value;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_CELL_CHECKER_TESTER_H
