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

    const auto SPACING = std::setw(20);
      
    constexpr TNATURAL UNDEFINED_INT = 99999;
    constexpr char NEWLINE = '\n';
    constexpr char EMPTYCELL = '*';
    constexpr char SEPARATOR = ' ';
      
    template<typename Ret, typename T, typename... Args>
    using GETTER = Ret(T::*)(Args...)const;

    template<typename Ret, typename T, typename... Args>
    using SETTER = Ret(T::*)(Args...);

  }
}

#endif //TOAST_TYPES_H
