//
//  ISerializable.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_ISERIALIZABLE_H
#define TOAST_API_ISERIALIZABLE_H

#include <iostream>
#include <iomanip> 
#include <memory>
#include <string>
#include <sstream>
#include <iostream>

#include "Types.h"

#include "GridFactory.h"

#include "IGrid.h"

using namespace toast::utils;

namespace toast { namespace io
{
    /*
     
     Needs some work but halfway there.
     Deserialization doesn't use delimiter
     Shouldn't all be in the same header.
     
     */
    template <char delimiter>
    static void Serialize(std::ostream& stream, const PTR<api::IGrid>& grid)
    {
        stream << grid->GetNrOfRows() << delimiter << grid->GetNrOfColumns() << NEWLINE;
        
        auto func = [&](size_t r, size_t c){
            auto cell = (*grid)(r,c);
            if(cell->HasValue())
                stream << (*cell)() << delimiter;
            else
                stream << EMPTYCELL << delimiter;
            
            if(c+1 == grid->GetNrOfColumns())
                stream << NEWLINE;
        };
        grid->Operation(func);
    }
    
    template <char delimiter>
    static void Deserialize(std::istream& stream, PTR<api::IGrid>& grid)
    {
        int rows = 0;
        int columns = 0;
        stream >> rows >> columns;
        grid = factory::GridFactory::CreateEmptySquareGrid(rows);
        
        auto func = [&](size_t r, size_t c){
            auto cell = (*grid)(r,c);
            std::string value = "";
            stream >> value;
            if(value[0] != EMPTYCELL)
                cell->SetValue(stoi(value));
        };
        grid->Operation(func);
    }
    
    template <char delimiter=' '>
    std::ostream& operator<<(std::ostream& os, const PTR<api::IGrid>& grid)
    {
        Serialize<delimiter>(os, grid);
        return os;
    }
    
    template <char delimiter=' '>
    std::istream& operator>>(std::istream& is, PTR<api::IGrid>& grid)
    {
        Deserialize<delimiter>(is, grid);
        return is;
    }
  }
}

#endif //TOAST_API_ISERIALIZABLE_H
