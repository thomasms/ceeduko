//
//  Grid.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Serialization.h"

#include "Grid.h"

namespace toast { namespace imp
  {
    
    Grid::Grid(size_t nr_of_rows, size_t nr_of_columns){
      CreateGrid(nr_of_rows, nr_of_columns);
    }
    
    Grid::~Grid(){
    }
    
    void Grid::CreateGrid(size_t nr_of_rows, size_t nr_of_columns){
#ifdef ASSERTIONS
      assert(nr_of_rows >= 0 );
      assert(nr_of_columns >= 0 );
#endif
      
      _cells.resize(0);
      for(size_t i=0;i<nr_of_rows;++i){
        _cells.push_back(factory::CellFactory::CreateEmptyCellRow(nr_of_columns));
      }
    }
    
    const PTR<api::ICell>& Grid::operator()(size_t row, size_t column) const{
      return GetCell(row, column);
    }
    
    const PTR<api::ICell>& Grid::GetCell(size_t row, size_t column) const{
#ifdef ASSERTIONS
      assert(row >= 0 && row < GetNrOfRows() );
      assert(column >= 0 && column < GetNrOfColumns() );
#endif
      
      return _cells[row][column];
    }
    
    void Grid::Clear(){
      for(auto row: _cells){
        for(auto cell: row){
          cell->Clear();
        }
      }
    }
    
    size_t Grid::GetNrOfRows() const{
      return _cells.size();
    }
    
    size_t Grid::GetNrOfColumns() const{
      size_t nr_of_columns = 0;
      if(GetNrOfRows() >0){
        nr_of_columns = _cells[0].size();
      }
      return nr_of_columns;
    }
    
    void Grid::Validate() const
    {
      for(auto& row: _cells){
        for(auto& cell: row){
          cell->Validate();
        }
      }
      
      //ToDo: implement logic to check maximum value of cell is consistent with grid size
    }
    
    void Grid::Deserialize(std::istream& is)
    {
      size_t nr_of_rows = 0;
      size_t nr_of_columns = 0;
      
      // read first line for row and columns sizes
      std::string line;
      std::getline(is, line);
      line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
      if((line.size() == 2) && (isdigit(line[0])) && (isdigit(line[1])))
      {
        nr_of_rows = stoi(line.substr(0,1));
        nr_of_columns = stoi(line.substr(1,1));
      }
      else
      {
        throw GeneralException("Invalid file format for Grid!");
      }
      
      CreateGrid(nr_of_rows, nr_of_columns);
      
      for(auto& row: _cells){
        for(PTR<api::ISerializable> cell: row){
          is >> cell;
        }
      }
    }
    
    void Grid::Serialize(std::ostream& os) const
    {
      os << SPACING << GetNrOfRows() << SEPARATOR << SPACING << GetNrOfColumns() << NEWLINE;
      
      for(auto& row: _cells){
        for(PTR<api::ISerializable> cell: row){
          os << SPACING << cell << SEPARATOR;
        }
        os << NEWLINE;
        os << NEWLINE;
        os << NEWLINE;
        os << NEWLINE;
      }
    }
    
  }
}