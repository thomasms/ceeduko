//
//  Cell.h
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_CELL_H
#define TOAST_IMP_CELL_H

#include <iostream>
#include <string>
#include <cctype>   

#include "Types.h"
#include "GeneralException.h"

#include "ICell.h"

using namespace toast::utils;

namespace toast { namespace imp
{
  constexpr TNATURAL k_unset_value = UNDEFINED_INT;
    
  class Cell : public api::ICell
  {
  public:
    Cell();
    ~Cell();
    
    inline TNATURAL operator()() const override{
      return GetValue();
    }
    
    inline TNATURAL GetValue() const override{
      return _value;
    }
    
    inline void SetValue(TNATURAL value) override{
      _value = value;
    }
    
    inline void Clear() override{
      _value = k_unset_value;
    }
    
    inline bool HasValue() const override{
      return _value != k_unset_value;
    }
    
    void Validate() const override;
    
    void Serialize(std::ostream& os) const override;
    void Deserialize(std::istream& is) override;
    
  private:
    TNATURAL _value;
    
  };
    
}
}
#endif //TOAST_IMP_CELL_H
