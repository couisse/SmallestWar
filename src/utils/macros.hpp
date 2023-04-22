#ifndef MACROS_HPP_INCLUDED
#define MACROS_HPP_INCLUDED


///log definition
#ifdef DBG

#include <iostream>
#define log(x) {std::cout << x << std::endl;}

#else

#define log(x) {}

#endif

#endif // MACROS_HPP_INCLUDED
