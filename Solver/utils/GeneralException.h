//
//  GeneralException.h
//  Solver
//
//  Created by Thomas Stainer on 08/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_GENERAL_EXCEPTION_H
#define TOAST_GENERAL_EXCEPTION_H

#include <exception>
#include <string>

namespace toast { namespace utils
  {
    // ToDo: implement other exception types
    class GeneralException : public std::exception
    {
      public:
      GeneralException(std::string text) : _what(text)
      {
      }
      
      virtual const char* what() const throw()
      {
        return _what.c_str();
      }
      
      private:
        std::string _what;
    };
  }
}

#endif //TOAST_GENERAL_EXCEPTION_H
