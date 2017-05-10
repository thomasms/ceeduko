//
//  SquareGrid.h
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_GRID_H
#define TOAST_IMP_GRID_H

#include <assert.h>
#include <vector>

#include "Defs.h"
#include "Types.h"
#include "GeneralException.h"

#include "CellFactory.h"

#include "ICell.h"
#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace imp
  {
    class Grid : public api::IGrid
    {
    public:
      Grid(size_t nr_of_rows, size_t nr_of_columns);
      ~Grid();
      
      // Overload the function call operator to access the cell
      const PTR<api::ICell>& operator()(size_t row, size_t column) const override;
      
      const PTR<api::ICell>& GetCell(size_t row, size_t column) const override;
      void Clear() override;
      size_t GetNrOfRows() const override;
      size_t GetNrOfColumns() const override;
      
      void Serialize(std::ostream& os) const override;
      void Deserialize(std::istream& is) override;
      
    private:
      void CreateGrid(size_t nr_of_rows, size_t nr_of_columns);
      
    private:
      std::vector< std::vector< PTR<api::ICell> > > _cells;
    };
    
  }
}
#endif //TOAST_IMP_GRID_H
