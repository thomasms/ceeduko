//
//  Block.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Block_h
#define Solver_Block_h

#include <memory>
#include <vector>

#include "Types.h"

#include "IDrawable.h"
#include "IRow.h"
#include "IBlock.h"

using namespace toast::utils;

namespace toast { namespace logic
  {
    class Block : public api::IBlock,
                  public api::IDrawable
    {
    public:
      Block(const std::vector<std::shared_ptr<api::IRow>>& rows);
      ~Block();
      
      void Draw(std::ofstream& writer) const override;
      
      inline const std::vector<std::shared_ptr<api::IRow>>& GetRows() const override
      {
        return _rows;
      }
    
      inline const int GetNumberOfRows() const override
      {
        return static_cast<int>(_rows.size());
      }
  
      const int GetNumberOfColumns() const override
      {
        if(GetNumberOfRows() >0)
          return _rows[0]->GetNumberOfCells();
        else
          return 0;
      }

      /**
       *@brief Set the value at the nth row at the mth column
       *@param[in] n The row index
       *@param[in] m The column index
       *@param[in] value The value to set
       */
      void SetValue(int n,int m, TNATURAL value) override;
    
    private:
      std::vector<std::shared_ptr<api::IRow>> _rows;
    };
    
  }
}

#endif
