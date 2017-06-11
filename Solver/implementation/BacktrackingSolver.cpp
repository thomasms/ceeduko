//
//  BacktrackingSolver.cpp
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "BacktrackingSolver.h"

namespace toast { namespace imp
  {
    BacktrackingSolver::BacktrackingSolver()
    {
    }
    
    BacktrackingSolver::~BacktrackingSolver()
    {
    }
    
    bool BacktrackingSolver::Solve(PTR<api::IGrid>& grid)
    {
      bool result = false;
      if(Initialise(grid))
        result = Loop(grid);
      
      return result;
    }
    
    
    bool BacktrackingSolver::VerifyGrid(PTR<api::IGrid>& grid) const
    {
      CellChecker checker(grid);
      
      bool result = true;
      auto func = [&](size_t r, size_t c){
        auto cell = (*grid)(r,c);
        if(!checker.IsOk(r,c,(*cell)())){
          result = false;
        }
      };
      (imp::GridOperation(grid))(func);
      
      return result;
    }
    
    bool BacktrackingSolver::Loop(PTR<api::IGrid>& grid)
    {
      // Get the next empty cell
      PTR<api::ICell> next_cell = nullptr;
      for(auto cell: _empty_cells){
        if(!cell->HasValue())
          next_cell = cell;
      }
      
      // If no empty cell remains, then we have solved it!
      if(next_cell == nullptr)
        return true;
      
      // loop over all possible numbers
      const TNATURAL start_number = 1;
      const TNATURAL end_number = static_cast<TNATURAL>(grid->GetNrOfColumns());
      
      // object for checking if a cell value is ok in that grid location
      CellChecker checker(grid);
      
      for(TNATURAL value=start_number;value<=end_number;++value){
        if(checker.IsOk(next_cell, value)){
          
          // try the value
          next_cell->SetValue(value);
          
          // recursively check if ok
          if(Loop(grid)){
            return VerifyGrid(grid);
          }
          
          // reaches here if not a valid value, clear the cell and try the next value
          next_cell->Clear();
        }
      }
      
      return false;
    }
        
    bool BacktrackingSolver::Initialise(PTR<api::IGrid>& grid)
    {
      // Clear the empty cells vector
      // These are the cells which have not been set values in the grid.
      _empty_cells.resize(0);
      
      // Check that the grid has been correctly setup - i.e. check existing values are ok.
      if(!VerifyGrid(grid))
        return false;
      
      // Get all of the empty cells
      auto func = [&](size_t r, size_t c){
        auto cell = (*grid)(r,c);
        if(!cell->HasValue()){
          _empty_cells.push_back(cell);
        }
      };
      (imp::GridOperation(grid))(func);
      
      return true;
    }
    
  }
}
