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
      //ToDo: implement
      return false;
    }
    
    
    std::vector<TNATURAL> CellChecker::GetValidSet(size_t row_index, size_t column_index) const
    {
      //ToDo: implement
      return std::vector<TNATURAL>();
    }
    
    std::vector<TNATURAL> CellChecker::GetRowSet(size_t row_index) const
    {
      //ToDo: implement
      return std::vector<TNATURAL>();
      
    }
    
    std::vector<TNATURAL> CellChecker::GetColumnSet(size_t column_index) const
    {
      //ToDo: implement
      return std::vector<TNATURAL>();
      
    }
  
  }
}
