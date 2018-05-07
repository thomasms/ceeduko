//
//  Definitions.h
//  Solver
//
//  Created by Thomas Stainer on 07/05/2017.
//  Copyright © 2017 Tom Stainer. All rights reserved.
//

#ifndef TOAST_UTILS_DEFINITIONS_H
#define TOAST_UTILS_DEFINITIONS_H

// Uncomment to enable assertions
//#define ASSERTIONS

#ifdef NAMESPACE_BEGIN
    #undef NAMESPACE_BEGIN
#endif
#define NAMESPACE_BEGIN(name) namespace name {

#ifdef NAMESPACE_END
    #undef NAMESPACE_END
#endif
#define NAMESPACE_END }

#ifdef NAMESPACE_USING
    #undef NAMESPACE_USING
#endif
#define NAMESPACE_USING(name) using namespace name;

#endif //TOAST_UTILS_DEFINITIONS_H

