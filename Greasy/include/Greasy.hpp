
#if GR_WINDOWS
    #if GR_DLLEXPORT
        #define API __declspec(dllexport)
    #else
        #define API __declspec(dllimport)
    #endif
#else
    #define API
#endif


#include <iostream>

#include "greet.hpp"