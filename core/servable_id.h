#ifndef _SERVING_SERVABLE_ID_H_
#define _SERVING_SERVABLE_ID_H_

#include <string>
#include <unordered_map>
#include "util/hash.h"



namespace serving {

struct ServableId {
    std::string name;
    int64_t version;
    std::string DebugString() const {
        std::string str = "{name: ";
        str.append(name);
        str.append(" version: ");
        str.append(std::to_string(version));
        return str;
    }

};

struct HashServableId {
    uint64_t operator()(const ServableId& id) {
        const uint64_t version_hash = [&]() -> uint64_t {
            if (id.version >= 0) {
                return std::hash<int64_t>()(id.version) * 0x9E3779B97F4A7C13;
            } else {
                return 0xDECAFCAFFE;
            }
        }();
        return HashCombine(version_hash, std::hash<std::string>()(id.name));
    }
};


inline bool operator==(const ServableId& a, const ServableId& b) {
  return a.version == b.version && a.name == b.name;
}

inline bool operator!=(const ServableId& a, const ServableId& b) {
  return !(a == b);
}

inline bool operator<(const ServableId& a, const ServableId& b) {
  const int strcmp_result = a.name.compare(b.name);
  if (strcmp_result != 0) {
    return strcmp_result < 0;
  }
  return a.version < b.version;
}

inline std::ostream& operator<<(std::ostream& out, const ServableId& id) {
  return out << id.DebugString();
}




}  // namespace serving

#endif