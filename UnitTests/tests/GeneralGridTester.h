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
        _grid->Clear();
        ValidateDefaultCells();
      }
      
    protected:
      std::vector<TNATURAL> CreateTestValues(){
        std::vector<TNATURAL> values = std::vector<TNATURAL>(_nr_of_rows*_nr_of_columns, 0);
        TNATURAL counter = 0;
        for(auto& e: values)
          e = _value + counter++;
        
        return values;
      }
      
      void SetValueCells(const std::vector<TNATURAL>& values){
        size_t i = 0;
        for(size_t r=0;r<_nr_of_rows;++r){
          for(size_t c=0;c<_nr_of_columns;++c){
            (*_grid)(r,c)->SetValue(values[i++]);
          }
        }
      }
      
      void ValidateCells(const std::vector<TNATURAL>& values){
        size_t i = 0;
        for(size_t r=0;r<_nr_of_rows;++r){
          for(size_t c=0;c<_nr_of_columns;++c){
            auto cell = (*_grid)(r,c);
            _cell_tester = std::make_shared<CellTester>(cell, &ICell::operator(), &ICell::SetValue, values[i++]);
            _cell_tester->Validate();
          }
        }
      }
      
      void ValidateDefaultCells(){
        for(size_t r=0;r<_nr_of_rows;++r){
          for(size_t c=0;c<_nr_of_columns;++c){
            auto cell = (*_grid)(r,c);
            _cell_tester = std::make_shared<CellTester>(cell, &ICell::operator(), &ICell::SetValue, 0);
            _cell_tester->ValidateDefault();
          }
        }
      }
      
    protected:
      TNATURAL _value;
      PTR<ITester>_cell_tester;
      PTR<api::IGrid> _grid;
      size_t _nr_of_rows;
      size_t _nr_of_columns;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_GENERAL_GRID_TESTER_H
