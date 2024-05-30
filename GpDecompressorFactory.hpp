#pragma once

#include "GpDecompressor.hpp"

namespace GPlatform {

class GpDecompressorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpDecompressorFactory)
    CLASS_DD(GpDecompressorFactory)

protected:
                                    GpDecompressorFactory   (void) noexcept = default;

public:
    virtual                         ~GpDecompressorFactory  (void) noexcept = default;

    virtual GpDecompressor::SP      NewInstance             (void) = 0;
};

}// namespace GPlatform
