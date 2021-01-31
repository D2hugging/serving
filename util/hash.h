#ifndef _SERVING_UTIL_HASH_H_
#define _SERVING_UTIL_HASH_H_

#include <cstdint>

namespace serving {

uint64_t HashCombine(uint64_t hash1, uint64_t hash2);


}  // namespace serving

#endif