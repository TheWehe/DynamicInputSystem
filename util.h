#ifndef UTIL_H
#define UTIL_H

#include <cstdint>



#define FOREACH_I_IN_RANGE(a, b) for(uint32_t i = (a); i < static_cast<uint32_t>(b); i++)
#define FOREACH_IT_IN_LIST(list) for(auto it = (list).begin(); it != (list).end(); it++)

#endif