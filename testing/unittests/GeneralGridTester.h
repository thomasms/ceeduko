//
//  GeneralGridTester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_GENERAL_GRID_TESTER_H
#define TOAST_UNIT_TESTS_GENERAL_GRID_TESTER_H

#include <memory>

#include "catch.hpp"

#include "ICell.h"
#include "IGrid.h"
#include "Grid.h"
#include "GridFactory.h"

#include "CellTester.h"
#include "ITester.h"

using namespace toast::api;
using namespace toast::utils;

namespace toast { namespace unittests
  {
    class GeneralGridTester : public ITester
    {
    public:
      GeneralGridTester(size_t nr_of_rows, size_t nr_of_columns, TNATURAL value)
      :
      _nr_of_rows(nr_of_rows),
      _nr_of_columns(nr_of_columns),
      _value(value)
      {
      }
      
      ~GeneralGridTester()
      {
      }
      
      void InitialiseDefault() override
      {
        Initialise();
      }
      
      void Initialise() override
      {
        REQUIRE(_grid == nullptr);
        _grid = factory::GridFactory::CreateEmptyGrid(_nr_of_rows,_nr_of_columns);
        REQUIRE(_grid != nullptr);
        REQUIRE(_grid->GetNrOfRows() == _nr_of_rows);
        REQUIRE(_grid->GetNrOfColumns() == _nr_of_columns);
        
        //validate grid data
        REQUIRE_NOTHROW(_grid->Validate());
      }
      
      void ValidateDefault() override
      {
        ValidateDefaultCells();
      }
      
      void Validate() override
      {
        auto values = CreateTestValues();
        SetValueCells(values);
        ValidateCells(values);
        
        //validate grid data
        REQUIRE_NOTHROW(_grid->Validate());
        
        REQUIRE_NOTHROW(_grid->Clear());
        
        ValidateDefaultCells();
      }
      
    protected:
      std::vector<TNATURAL> CreateTestValues(){
        std::vector<TNATURAL> values = std::vector<TNATURAL>(_nr_of_rows*_nr_of_columns, 0);
        TNATURAL start = 1;
        TNATURAL end   = std::min(_nr_of_rows, _nr_of_columns);
        TNATURAL counter = start;
        for(auto& e: values){
            if(counter >= end) counter = start;
            e = _value + counter++;
        }
        return values;
      }
      
      void SetValueCells(const std::vector<TNATURAL>& values){
        size_t i = 0;
        auto func = [&](size_t r, size_t c){
          (*_grid)(r,c)->SetValue(values[i++]);
        };
        
        _grid->Operation(func);
      }
      
      void ValidateCells(const std::vector<TNATURAL>& values){
        size_t i = 0;
        auto func = [&](size_t r, size_t c){
          auto cell = (*_grid)(r,c);
          _cell_tester = std::make_shared<CellTester>(cell, &ICell::operator(), &ICell::SetValue, values[i++]);
          _cell_tester->Validate();
        };
        
        _grid->Operation(func);
      }
      
      void ValidateDefaultCells(){
        auto func = [&](size_t r, size_t c){
          auto cell = (*_grid)(r,c);
          _cell_tester = std::make_shared<CellTester>(cell, &ICell::operator(), &ICell::SetValue, 0);
          _cell_tester->ValidateDefault();
        };
        
        _grid->Operation(func);
      }
      
    protected:
      size_t _nr_of_rows;
      size_t _nr_of_columns;
      TNATURAL _value;
      PTR<ITester> _cell_tester;
      PTR<api::IGrid> _grid;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_GENERAL_GRID_TESTER_H
