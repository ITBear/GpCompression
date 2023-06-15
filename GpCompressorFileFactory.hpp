#pragma once

#include "GpCompressorFile.hpp"

namespace GPlatform {

class GpCompressorFileFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorFileFactory)
    CLASS_DD(GpCompressorFileFactory)

protected:
                                    GpCompressorFileFactory     (void) noexcept = default;

public:
    virtual                         ~GpCompressorFileFactory    (void) noexcept = default;

    virtual GpCompressorFile::SP    NewInstance                 (void) = 0;
};

}//namespace GPlatform
