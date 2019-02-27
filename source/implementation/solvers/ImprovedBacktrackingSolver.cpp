//
//  ImprovedBacktrackingSolver.cpp
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "ImprovedBacktrackingSolver.h"

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(imp)
        
    bool ImprovedBacktrackingSolver::Solve()
    {
      bool result = false;
      if(Initialise())
        result = FindNext();
      
      return result;
    }
    
    bool ImprovedBacktrackingSolver::VerifyGrid() const
    {
      bool result = true;
      auto func = [&](size_t r, size_t c){
        auto cell = (*_grid)(r,c);
        if(!_cell_checker->IsOk(r,c,(*cell)())){
          result = false;
        }
      };
      _grid->Operation(func);
      
      return result;
    }
    
    bool ImprovedBacktrackingSolver::FindNext()
    {
      // Get the next empty cell
      PTR<api::ICell> next_cell = nullptr;
      int index = -1;
      for(int i=0; i<static_cast<int>(_empty_cells.size());++i){
        if(!(*_empty_cells[i])){
          next_cell = _empty_cells[i];
          index = i;
          break;
        }
      }
      
      // If no empty cell remains, then we have solved it!
      if(next_cell == nullptr)
        return true;
      
      // loop over all possible numbers
      for(TNATURAL value=1; value<=static_cast<TNATURAL>(_grid->GetNrOfColumns()); ++value){
        if(_cell_checker->IsOk(_empty_cell_r_c[index].first, _empty_cell_r_c[index].second, value)){
          
          // try the value
          (*next_cell)(value);
          
          // recursively check if ok
          if(FindNext()){
            return VerifyGrid();
          }
          
          // reaches here if not a valid value, clear the cell and try the next value
          next_cell->Clear();
        }
      }
      
      return false;
    }

    bool ImprovedBacktrackingSolver::Initialise()
    {
      // Clear the empty cells vector
      // These are the cells which have not been set values in the grid.
      _empty_cells.resize(0);
      _empty_cell_r_c.resize(0);
      
      // Check that the grid has been correctly setup - i.e. check existing values are ok.
      if(!VerifyGrid())
        return false;
      
      // Get all of the empty cells
      auto func = [&](size_t r, size_t c){
        auto cell = (*_grid)(r,c);
        if(!(*cell)){
          _empty_cells.push_back(cell);
          _empty_cell_r_c.push_back(std::make_pair(r,c));
        }
      };
      _grid->Operation(func);
      
      return true;
    }

    void ImprovedBacktrackingSolver::CheckGridDimensions() const
    {
      //check the grid dimensions - for this solver it must be square and of square size i.e. 4, 9, 16, etc..
      if(_grid->GetNrOfRows() != _grid->GetNrOfColumns())
        throw SolverException("This solver only supports square grids");
      
      auto sub_square_size = sqrt(static_cast<TVALUE>(_grid->GetNrOfRows()));
      
      if(ceil(sub_square_size) != sub_square_size)
        throw SolverException("This solver only supports square number dimensions, i.e. size of 4x4, 9x9, 16x16, etc");
    }

NAMESPACE_END //imp
NAMESPACE_END //toast
