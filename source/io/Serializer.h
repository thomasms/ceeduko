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
    template <char delimiter, class Container>
    void split(const std::string& str, Container& cont)
    {
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            cont.push_back(token);
        }
    }
    
    template <char delimiter>
    static void Serialize(std::ostream& stream, const PTR<api::IGrid>& grid)
    {
        stream << grid->GetNrOfRows() << delimiter << grid->GetNrOfColumns() << NEWLINE;
        
        auto func = [&](size_t r, size_t c){
            auto cell = (*grid)(r,c);
            if(cell->HasValue())
                stream << (*(*grid)(r,c))() << delimiter;
            else
                stream << EMPTYCELL << delimiter;
            
            if(c+1 == grid->GetNrOfColumns())
                stream << NEWLINE;
        };
        grid->Operation(func);
    }
    
    template <char delimiter>
    static const PTR<api::IGrid>& Deserialize(std::istream& stream)
    {
        std::string board = "";
        stream >> board;
        std::vector<std::string> lines;
        split<NEWLINE>(board, lines);
        
        // todo
        return nullptr;
    }
    
  }
}

#endif //TOAST_API_ISERIALIZABLE_H
