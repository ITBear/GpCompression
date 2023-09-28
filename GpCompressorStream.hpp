#pragma once

#include "GpCompression_global.hpp"

#include "../GpCore2/GpUtils/Macro/GpMacroClass.hpp"
#include "../GpCore2/GpUtils/Types/Containers/GpContainersT.hpp"
#include "../GpCore2/GpUtils/Streams/GpByteReader.hpp"
#include "../GpCore2/GpUtils/Streams/GpByteWriter.hpp"

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
