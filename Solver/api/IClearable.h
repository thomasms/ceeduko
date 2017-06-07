//
//  IClearable.h
//  Solver
//
//  Created by Thomas Stainer on 06/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_ICLEARABLE_H
#define TOAST_API_ICLEARABLE_H

using namespace toast::utils;

namespace toast { namespace api
  {
    /** @brief Interface for object that implements Clear.
     *
     *  Most objects in the API require an object to be reset or cleared,
     *  this interface enables that function.
     */
    class IClearable
    {
    public:
      virtual ~IClearable(){};
      
      /* @brief Clears the object data
       *
       */
      virtual void Clear() = 0;
    };
    
  }
}

#endif //TOAST_API_ICLEARABLE_H
