#ifndef MACROS_HPP_INCLUDED
#define MACROS_HPP_INCLUDED


///log definition
#ifdef DBG

#include <iostream>
#define console_log(x) {std::cout << x << std::endl;}

#else

#define console_log(x) {}

#endif

#endif // MACROS_HPP_INCLUDED
