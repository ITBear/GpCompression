#pragma once

#include "GpCompression_global.hpp"

namespace GPlatform {

class GpCompressorStream
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorStream)
    CLASS_DD(GpCompressorStream)

protected:
                        GpCompressorStream  (void) noexcept = default;

public:
    virtual             ~GpCompressorStream (void) noexcept = default;

    virtual void        Compress            (GpByteReader&  aReader) = 0;
    virtual void        Decompress          (GpByteWriter&  aWriter) = 0;
};

}//namespace GPlatform
