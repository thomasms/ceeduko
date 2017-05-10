//
//  IGrid.h
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_IGRID_H
#define TOAST_API_IGRID_H

#include "Types.h"

#include "IClearable.h"
#include "ICell.h"
#include "ISerializable.h"

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for the grid object, the two dimensional
     *         object containing the cells.
     *
     *         This interface is for a generic grid which allows for a different 
     *         number of rows and columns. A grid cannot be resized once constructed.
     */
    class IGrid : public IClearable,
                  public ISerializable
    {
    public:
      virtual ~IGrid(){};
      
      /* @brief Returns a shared pointer to the cell given the row and column indices
       *        in the grid.
       *        Note that indices are zero based.
       *
       * @param[in] row Is the row index on the grid, cannot exceed the number of rows - 1 and must be >= 0
       * @param[in] column Is the column index on the grid, cannot exceed the number of columns - 1 and must be >= 0
       * @return A constant shared pointer to the cell.
       */
      virtual const PTR<ICell>& operator()(size_t row, size_t column) const = 0;
      
      /* @brief Returns a shared pointer to the cell given the row and column indices
       *        in the grid. 
       *        Note that indices are zero based.
       *
       * @param[in] row Is the row index on the grid, cannot exceed the number of rows - 1 and must be >= 0
       * @param[in] column Is the column index on the grid, cannot exceed the number of columns - 1 and must be >= 0
       * @return A constant shared pointer to the cell.
       */
      virtual const PTR<ICell>& GetCell(size_t row, size_t column) const = 0;
      
      /* @brief Returns the number of the rows in the grid.
       *
       * @return The number of rows.
       */
      virtual size_t GetNrOfRows() const = 0;
      
      /* @brief Returns the number of the columns in the grid.
       *
       * @return The number of columns.
       */
      virtual size_t GetNrOfColumns() const = 0;
    };
    
  }
}

#endif //TOAST_API_IGRID_H
