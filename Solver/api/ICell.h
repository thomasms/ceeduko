//
//  ICell.h
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_ICELL_H
#define TOAST_API_ICELL_H

#include <iostream>

#include "Types.h"

#include "IClearable.h"
#include "ISerializable.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for the cell object, the basic constituent
     *        for the grid.
     */
    class ICell : public IClearable,
                  public ISerializable
    {
    public:
      virtual ~ICell(){};
      
      virtual TNATURAL operator()() const = 0;
      virtual TNATURAL GetValue() const = 0;
      virtual void SetValue(TNATURAL value) = 0;
      virtual bool HasValue() const = 0;
    };
        
  }
}

#endif //TOAST_API_ICELL_H
