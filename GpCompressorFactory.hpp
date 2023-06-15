#pragma once

#include "GpCompressor.hpp"

namespace GPlatform {

class GpCompressorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorFactory)
    CLASS_DD(GpCompressorFactory)

protected:
                                    GpCompressorFactory     (void) noexcept = default;

public:
    virtual                         ~GpCompressorFactory    (void) noexcept = default;

    virtual GpCompressor::SP        NewInstance             (void) = 0;
};

}//namespace GPlatform
