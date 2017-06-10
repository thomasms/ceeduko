//
//  BacktrackingSolver.cpp
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "GeneralException.h"

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
      // Check that the grid has been correctly setup - i.e. check existing values are ok.
      VerifyGrid(grid);
      
      // Operations for on the grid
      GridOperation op(grid);
      
      // object for checking if a cell value is ok in that grid location
      CellChecker checker(grid);
      
      // ToDo: implement algorithm
      
      // find next unset cell
      
      // try start_number
      
      // check if number is <= max_value
      // if yes:
      //  check if ok:
      //    if ok - go to next cell
      //    if not ok increment number and go to check again
      // if no:
      //  go back to start number and go to check again
      //
      
      
      return true;
    }
    
    
    bool BacktrackingSolver::VerifyGrid(PTR<api::IGrid>& grid) const
    {
      CellChecker checker(grid);
      
      for(size_t r=0;r<grid->GetNrOfRows();++r){
        for(size_t c=0;c<grid->GetNrOfColumns();++c){
          auto cell = (*grid)(r,c);
          if(!checker.IsOk(r,c,(*cell)())){
            return false;
          }
        }
      }
      
      return true;
    }
    
  }
}
