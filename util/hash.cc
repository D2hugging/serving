#include "util/hash.h"

namespace serving {
    
uint64_t HashCombine(const uint64_t hash1, const uint64_t hash2) {
  return hash1 ^ (hash2 + 0x9e3779b97f4a7800 + (hash1 << 10) + (hash1 >> 4));
}

}  // namespace serving