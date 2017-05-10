//
//  FileIO.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IO_FILE_IO_H
#define TOAST_IO_FILE_IO_H

#include <fstream>

#include "GeneralException.h"
#include "Types.h"

#include "Serialization.h"

#include "ISerializable.h"

using namespace toast::imp;

namespace toast { namespace io
  {
    void WriteToFile(std::string filename, const PTR<api::ISerializable>& serializable_object)
    {
      std::ofstream file(filename);
      if(!file)
        throw utils::GeneralException("Cannot open file: " + filename);
      
      file << serializable_object;
      file.close();
    }
    
    void ReadFromFile(std::string filename, PTR<api::ISerializable> serializable_object)
    {
      std::ifstream file(filename);
      if(!file)
        throw utils::GeneralException("Cannot open file: " + filename);
      
      file >> serializable_object;
      file.close();
    }
  }
}
#endif //TOAST_IO_FILE_IO_H
