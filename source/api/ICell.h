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
#include "IValidatable.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for the cell object, the basic constituent
     *        for the grid.
     */
    class ICell : public IClearable,
                  public IValidatable
    {
    public:
      virtual ~ICell(){};
      
      /* @brief Returns the value of the cell.
       *        Does the exact operation as ICell::GetValue()
       *
       * @return The cell value
       */
      virtual TNATURAL operator()() const = 0;
      
      /* @brief Returns the value of the cell.
       *
       * @return The cell value
       */
      virtual TNATURAL GetValue() const = 0;
      
      /* @brief Sets the value of the cell.
       *
       * @param[in] The value to set the cell with
       */
      virtual void SetValue(TNATURAL value) = 0;
      
      /* @brief Returns true if the cell has a value, false otherwise.
       *
       * @return True if cell has a value, false otherwise.
       */
      virtual bool HasValue() const = 0;
    };
        
  }
}

#endif //TOAST_API_ICELL_H
