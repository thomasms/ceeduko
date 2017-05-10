//
//  ITester.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UNIT_TESTS_ITESTER_H
#define TOAST_UNIT_TESTS_ITESTER_H

namespace toast { namespace unittests
  {
    /** @brief Interface for an object that will be unit tested
     *
     */
    class ITester
    {
    public:
      virtual ~ITester(){};
      virtual void InitialiseDefault() = 0;
      virtual void Initialise() = 0;
      virtual void ValidateDefault() = 0;
      virtual void Validate() = 0;
    };
    
  }
}

#endif //TOAST_UNIT_TESTS_ITESTER_H
