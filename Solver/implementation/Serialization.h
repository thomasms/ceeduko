//
//  Serialization.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_SERIALIZATION_H
#define TOAST_IMP_SERIALIZATION_H

#include "Types.h"

#include "ISerializable.h"

namespace toast { namespace imp
  {
    std::istream& operator>>(std::istream& is, PTR<api::ISerializable>& object);
    std::ostream& operator<<(std::ostream& os, const PTR<api::ISerializable>& object);
    
  }
}
#endif //TOAST_IMP_SERIALIZATION_H
