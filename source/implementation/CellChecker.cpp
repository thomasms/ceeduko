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
    
    bool CellChecker::IsOk(PTR<api::ICell>& cell, TNATURAL value) const
    {
      auto r_and_c = FindCellLocation(cell);
      return IsOk(r_and_c.first,r_and_c.second,value);
    }
    
    bool CellChecker::IsOk(size_t row_index, size_t column_index, TNATURAL value) const
    {
      // If value is undefined 
      if(value == UNDEFINED_INT)
        return true;
      
      // If it has been set then check rows and columns
      bool in_row = IsInRow(row_index, column_index, value);
      bool in_column = IsInColumn(row_index, column_index, value);
      bool in_sub_grid = IsInSubGrid(row_index, column_index, value);
      return (!in_row && !in_column && !in_sub_grid);
    }
    
    bool CellChecker::IsInRow(size_t row_index, size_t column_index, TNATURAL value) const
    {
      for(size_t c=0;c<_grid->GetNrOfColumns();++c)
      {
        // Ignore the cell in question
        if(c == column_index)continue;
        
        auto cell = (*_grid)(row_index, c);
        if(CheckCell(cell,value))
          return true;
      }
      return false;
    }
    
    bool CellChecker::IsInColumn(size_t row_index, size_t column_index, TNATURAL value) const
    {
      for(size_t r=0;r<_grid->GetNrOfRows();++r){
        
        // Ignore the cell in question
        if(r == row_index)continue;
        
        auto cell = (*_grid)(r, column_index);
        if(CheckCell(cell,value))
          return true;
      }
      return false;
    }
    
    bool CellChecker::IsInSubGrid(size_t row_index, size_t column_index, TNATURAL value) const
    {
      const size_t sub_square_size = static_cast<size_t>(sqrt(static_cast<TVALUE>(_grid->GetNrOfColumns())));
      const size_t start_row_index = row_index - (row_index%sub_square_size);
      const size_t start_column_index = column_index - (column_index%sub_square_size);
      const size_t end_row_index = start_row_index + sub_square_size;
      const size_t end_column_index = start_column_index + sub_square_size;
      
      for(size_t r=start_row_index;r<end_row_index;++r){
        for(size_t c=start_column_index;c<end_column_index;++c){
          // Ignore the cell in question
          if((r == row_index) && (c == column_index))continue;
          
          auto cell = (*_grid)(r, c);
          if(CheckCell(cell,value))
            return true;
        }
      }
      return false;
    }
    
    std::pair<size_t,size_t> CellChecker::FindCellLocation(PTR<api::ICell>& cell) const
    {
      std::pair<size_t,size_t> r_and_c;
      auto func = [&](size_t r, size_t c){
        PTR<api::ICell> cell_rc = (*_grid)(r,c);
        if(cell_rc == cell){
          r_and_c = std::make_pair(r, c);
        }
      };
      
      _grid->Operation(func);
      
      return r_and_c;
    }
    
  }
}
