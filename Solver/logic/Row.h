//
//  Row.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Row_h
#define Solver_Row_h

#include <vector>

#include "Types.h"
#include "Cell.h"

#include "IDrawable.h"
#include "IRow.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    class Row : public api::IRow,
                public api::IDrawable
    {
    public:
      Row(const std::vector<std::shared_ptr<api::ICell>>& cells);
      ~Row();
      
      void Draw(std::ofstream& writer) const override;
    
      inline const std::shared_ptr<api::ICell>& GetCell(int index) const override
      {
        return _cells[index];
      }
    
      const int GetNumberOfCells() const override
      {
        return static_cast<int>(_cells.size());
      }
  
    private:
      std::vector<std::shared_ptr<api::ICell>> _cells;
      
    };
    
  }
}

#endif
