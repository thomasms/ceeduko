//
//  Types.h
//  Solver
//
//  Created by Tom Stainer on 04/05/2017.
//  Copyright (c) 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_TYPES_H
#define TOAST_TYPES_H

#include <iomanip>
#include <memory>
#include <string>
#include <vector>

namespace toast { namespace utils
  {
    using TVALUE = double;
    using TNATURAL = int;
    
    template<class T>
    using PTR = std::shared_ptr<T>;
    
    const auto UNDEFINED_INT = -1;
    const auto SPACING = std::setw(20);
    const char NEWLINE = '\n';
    const char EMPTYCELL = '*';
    const char SEPARATOR = ' ';
  }
}

#endif //TOAST_TYPES_H
