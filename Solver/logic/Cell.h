//
//  Cell.h
//  Solver
//
//  Created by Tom Stainer on 13/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_Cell_h
#define Solver_Cell_h

#include "Types.h"

#include "IDrawable.h"
#include "ICell.h"

using namespace toast::utils;

namespace toast { namespace logic
{
  class Cell : public api::ICell,
               public api::IDrawable
  {
    public:
      Cell();    
      ~Cell();
    
      void Draw(std::ofstream& writer) const override;
    
      inline const TNATURAL GetValue() const override
      {
        return _value;
      }
    
      inline void SetValue(const TNATURAL value) override
      {
        _value = value;
      }

      const static TNATURAL DefaultValue;
    private:
      void DrawTop(std::ofstream& writer) const;
      void DrawSide(std::ofstream& writer) const;
      void DrawSideWithValue(std::ofstream& writer) const;
      void DrawBottom(std::ofstream& writer) const;
  
    private:
      TNATURAL _value;
  };

}
}
#endif
