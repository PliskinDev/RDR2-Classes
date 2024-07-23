#pragma once

#include <string_view>
#include <cstdint>

namespace rage 
{
    using joaat_t = std::uint32_t;
    inline constexpr joaat_t joaat(std::string_view name) 
    {
        joaat_t hash = 0;
        for (char c : name) {
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            }
            hash += (c);
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        return hash;
    }
}
