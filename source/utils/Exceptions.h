//
//  GeneralException.h
//  Solver
//
//  Created by Thomas Stainer on 08/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_EXCEPTIONS_H
#define TOAST_EXCEPTIONS_H

#include <exception>
#include <string>

NAMESPACE_BEGIN(toast)
NAMESPACE_BEGIN(utils)

    class GeneralException : public std::exception
    {
        public:
            GeneralException(std::string text) : _what(text)
            {
            }
        
            virtual ~GeneralException() throw()
            {
            }
        
            virtual const char* what() const throw()
            {
                return _what.c_str();
            }
      
        protected:
            std::string _what;
    };
    
    class ValidationException : public GeneralException
    {
        public:
            ValidationException(std::string text) : GeneralException(text)
            {
            }
        
            virtual ~ValidationException() throw()
            {
            }
    };
    
    class CellValidationException : public ValidationException
    {
        public:
            CellValidationException(std::string text) : ValidationException(text)
            {
            }
        
            virtual ~CellValidationException() throw()
            {
            }
    };
    
    class GridValidationException : public ValidationException
    {
        public:
            GridValidationException(std::string text) : ValidationException(text)
            {
            }
        
            virtual ~GridValidationException() throw()
            {
            }
    };
    
    class SolverException : public GeneralException
    {
        public:
            SolverException(std::string text) : GeneralException(text)
            {
            }
        
            virtual ~SolverException() throw()
            {
            }
    };
    
NAMESPACE_END // utils
NAMESPACE_END // toast

#endif //TOAST_EXCEPTIONS_H
