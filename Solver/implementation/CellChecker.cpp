//
//  CellChecker.cpp
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "CellChecker.h"

namespace toast { namespace imp
  {
    
    CellChecker::CellChecker(PTR<api::IGrid>& grid)
    :
    _grid(grid)
    {
    }
  
    CellChecker::~CellChecker()
    {
    }
  
    bool CellChecker::IsOk(size_t row_index, size_t column_index, TNATURAL value) const
    {
      bool in_row = IsInRow(row_index, value);
      bool in_column = IsInColumn(column_index, value);
      return (!in_row && !in_column);
    }
    
    
    bool CellChecker::IsInRow(size_t row_index, TNATURAL value) const
    {
      for(int c=0;c<_grid->GetNrOfColumns();++c){
        auto cell = (*_grid)(row_index, c);
        if(CheckCell(cell,value))
          return true;
      }
      return false;
    }
    
    bool CellChecker::IsInColumn(size_t column_index, TNATURAL value) const
    {
      for(int r=0;r<_grid->GetNrOfRows();++r){
        auto cell = (*_grid)(r, column_index);
        if(CheckCell(cell,value))
          return true;
      }
      return false;
    }
    
    bool CellChecker::CheckCell(PTR<api::ICell>& cell, TNATURAL value) const{
      if(cell->HasValue() && (*cell)() == value ){
        return true;
      }
      else{
        return false;
      }
    }
  }
}
