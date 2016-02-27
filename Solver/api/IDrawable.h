//
//  IDrawable.h
//  Solver
//
//  Created by Tom Stainer on 26/02/2016.
//  Copyright (c) 2016 Tom Stainer. All rights reserved.
//

#ifndef Solver_IDrawable_h
#define Solver_IDrawable_h

#include <iostream>
#include <iomanip>
#include <fstream>

namespace toast { namespace api
  {
    class IDrawable
    {
    public:
      virtual ~IDrawable(){};
      virtual void Draw( std::ofstream& writer ) const = 0;
      
    protected:
      IDrawable(){};
      
    };
    
  }
}

#endif
