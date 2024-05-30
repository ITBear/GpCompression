#pragma once

#include "GpCompression_global.hpp"

#include <GpCore2/GpUtils/Macro/GpMacroClass.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpContainersT.hpp>
#include <GpCore2/GpUtils/Types/Containers/GpBytesArray.hpp>

namespace GPlatform {

class GpDecompressor
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpDecompressor)
    CLASS_DD(GpDecompressor)

protected:
                            GpDecompressor      (void) noexcept = default;

public:
    virtual                 ~GpDecompressor     (void) noexcept = default;

    virtual void            Close               (void) noexcept = 0;
    virtual void            OpenFile            (std::string_view aFileName) = 0;
    virtual size_t          ElementsCount       (void) const = 0;
    virtual std::string     ElementName         (const size_t aElementId) const = 0;
    virtual GpBytesArray    DecompressElement   (const size_t aElementId) const = 0;
    virtual GpBytesArray    DecompressElement   (std::string_view aElementName) const = 0;
    //virtual void          DecompressElement   (std::string_view aOutFileName) const = 0;
};

}// namespace GPlatform
