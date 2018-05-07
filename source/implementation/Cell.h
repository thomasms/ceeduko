//
//  Cell.h
//  Solver
//
//  Created by Thomas Stainer on 04/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_IMP_CELL_H
#define TOAST_IMP_CELL_H

#include <iostream>
#include <string>
#include <cctype>   

#include "Definitions.h"
#include "Types.h"
#include "Exceptions.h"

#include "ICell.h"

NAMESPACE_USING(toast::utils)

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(imp)

    constexpr TNATURAL k_unset_value = UNDEFINED_INT;

    class Cell : public api::ICell
    {
    public:
        Cell();
        Cell(TNATURAL value);
        ~Cell();

        inline TNATURAL operator()() const override{
            return _value;
        }

        inline void operator()(TNATURAL value) override{
            _value = value;
        }

        inline operator bool() const override{
            return _value != k_unset_value;
        }
        
        inline void Clear() override{
            _value = k_unset_value;
        }

        void Validate() const override;
        
    private:
        TNATURAL _value;
    
    };
    
NAMESPACE_END //imp
NAMESPACE_END //toast

#endif //TOAST_IMP_CELL_H
