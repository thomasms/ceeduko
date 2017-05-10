//
//  BasicAccessor.h
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_BASIC_ACCESSOR_H
#define TOAST_IMP_BASIC_ACCESSOR_H

namespace toast { namespace imp
  {
    template<class T>
    class BasicAccessor
    {
    public:
      BasicAccessor() : _value(T{}){};
      
      inline const T& Get() const
      {
        return _value;
      }
      
      inline void Set(const T& value)
      {
        _value = value;
      }
      
    private:
      T _value;
    };
  }
}

#endif //TOAST_IMP_BASIC_ACCESSOR_H
