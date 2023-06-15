#pragma once

#include "GpCompression_global.hpp"

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
    virtual void            OpenFile            (std::u8string_view aFileName) = 0;
    virtual size_t          ElementsCount       (void) const = 0;
    virtual std::u8string   ElementName         (const size_t aElementId) const = 0;
    virtual GpBytesArray    DecompressElement   (const size_t aElementId) const = 0;
    virtual GpBytesArray    DecompressElement   (std::u8string_view aElementName) const = 0;
    //virtual void          DecompressElement   (std::u8string_view aOutFileName) const = 0;
};

}//namespace GPlatform
