#pragma once

#include <GpCompression/GpCompression_global.hpp>
#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>

namespace GPlatform {

class GpCompressorFile
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorFile)
    CLASS_DD(GpCompressorFile)

protected:
                        GpCompressorFile    (void) noexcept = default;

public:
    virtual             ~GpCompressorFile   (void) noexcept = default;

    virtual void        Compress            (std::string_view   aPathIn,
                                             std::string_view   aFileOut) = 0;
    virtual void        Decompress          (std::string_view   aFileIn,
                                             std::string_view   aPathOut) = 0;
};

}// namespace GPlatform
