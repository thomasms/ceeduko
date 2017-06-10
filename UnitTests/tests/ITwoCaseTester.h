//
//  ITwoCaseTester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_ITWO_CASE_TESTER_H
#define TOAST_UNIT_TESTS_ITWO_CASE_TESTER_H

namespace toast { namespace unittests
  {
    /** @brief Interface for an object that will be unit tested
     *
     */
    class ITwoCaseTester
    {
    public:
      virtual ~ITwoCaseTester(){};
      
      virtual void ValidateSunny() = 0;
      virtual void ValidateRainy() = 0;
      
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_ITWO_CASE_TESTER_H
