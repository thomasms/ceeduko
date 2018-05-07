//
//  Assertions.h
//  Solver
//
//  Created by Thomas Stainer on 09/06/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_ASSERTIONS_H
#define TOAST_UNIT_TESTS_ASSERTIONS_H

#include <string>

#include "catch.hpp"

namespace toast { namespace unittests
  {
    template<typename T, typename EXC>
    void AssertExceptionMsg(std::function<T>& func, std::string expected_msg){
      bool exception_thrown = false;
      try{
        REQUIRE(exception_thrown == false);
        func();
      }
      catch(EXC& ex){
        exception_thrown = true;
        REQUIRE(ex.what() == expected_msg);
      }
      catch( ... ){
        REQUIRE(false);
      }
      REQUIRE(exception_thrown == true);
    }
  }
}

#endif //TOAST_UNIT_TESTS_ASSERTIONS_H
