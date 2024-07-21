#pragma once

namespace rage
{
    class datBase
    {
    public:
        virtual ~datBase() = default;
    };
    static_assert(sizeof(datBase) == 0x8);
}