#pragma once

#include "GpCompression_global.hpp"

namespace GPlatform {

class GpCompressor
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressor)
    CLASS_DD(GpCompressor)

protected:
                            GpCompressor        (void) noexcept = default;

public:
    virtual                 ~GpCompressor       (void) noexcept = default;

    virtual void            Close               (void) noexcept = 0;
    virtual void            OpenFile            (std::u8string_view aFileName) = 0;
    virtual void            CompressAndAdd      (std::u8string_view aPathOrFile) = 0;
};

}//namespace GPlatform
