//
//  BasicAccessorUnitTests.cpp
//  Solver
//
//  Created by Thomas Stainer on 05/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "catch.hpp"

#include "BasicAccessor.h"

using namespace toast::imp;

namespace toast { namespace unittests {
  
  // helper functions
  template<class T>
  void VerifySetter(BasicAccessor<T>& accessor, const T& value){
    accessor.Set(value);
    REQUIRE(accessor.Get() == value);
  }
  
  template<class T>
  void VerifySetterPtr(BasicAccessor<T*>& accessor, T value){
    accessor.Set(&value);
    REQUIRE(accessor.Get() == &value);
    REQUIRE(*accessor.Get() == value);
  }
  
  // Tests
  TEST_CASE( "Double Accessor", "[BasicAccessor]" ) {
    BasicAccessor<double> accessor;
    REQUIRE(accessor.Get() == 0.0);
    
    VerifySetter<double>(accessor, 2.4);
  }
  
  TEST_CASE( "Int Accessor", "[BasicAccessor]" ) {
    BasicAccessor<int> accessor;
    REQUIRE(accessor.Get() == 0);
    
    VerifySetter<int>(accessor, 8);
  }
  
  TEST_CASE( "Ptr Int Accessor", "[BasicAccessor]" ) {
    BasicAccessor<int*> accessor;
    REQUIRE(accessor.Get() == nullptr);
    
    VerifySetterPtr<int>(accessor,8);
  }
  
  TEST_CASE( "Ptr Double Accessor", "[BasicAccessor]" ) {
    BasicAccessor<double*> accessor;
    REQUIRE(accessor.Get() == nullptr);
    
    VerifySetterPtr<double>(accessor,4.97);
  }
  
}
}

