//
//  Serialization.cpp
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#include "Serialization.h"

namespace toast { namespace imp
  {
    std::istream& operator>>(std::istream& is, PTR<api::ISerializable>& object)
    {
      object->Deserialize(is);
      return is;
    }
    
    std::ostream& operator<<(std::ostream& os, const PTR<api::ISerializable>& object)
    {
      object->Serialize(os);
      return os;
    }
  }
}
