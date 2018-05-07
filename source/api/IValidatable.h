//
//  IValidatable.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_API_IVALIDATABLE_H
#define TOAST_API_IVALIDATABLE_H

NAMESPACE_USING(toast::utils)

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(api)

    /** @brief Interface for object that implements Validate.
     *
     *  Most objects in the API require an object to be validated,
     *  this interface enables that function.
     */
    class IValidatable
    {
    public:
      virtual ~IValidatable(){};
      
      /* @brief Validates the object data
       *
       */
      virtual void Validate() const = 0;
    };
    
NAMESPACE_END //api
NAMESPACE_END //toast

#endif //TOAST_API_IVALIDATABLE_H
