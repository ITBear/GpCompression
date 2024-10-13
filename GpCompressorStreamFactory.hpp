#pragma once

#include <GpCompression/GpCompressorStream.hpp>

namespace GPlatform {

class GpCompressorStreamFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorStreamFactory)
    CLASS_DD(GpCompressorStreamFactory)

protected:
                                    GpCompressorStreamFactory   (void) noexcept = default;

public:
    virtual                         ~GpCompressorStreamFactory  (void) noexcept = default;

    virtual GpCompressorStream::SP  NewInstance                 (void) = 0;
};

}// namespace GPlatform
