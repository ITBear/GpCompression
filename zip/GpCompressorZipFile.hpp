#pragma once

#include "../GpCompressorFile.hpp"

namespace GPlatform {

class GpCompressorZipFile final: public GpCompressorFile
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorZipFile)
    CLASS_DD(GpCompressorZipFile)

public:
                        GpCompressorZipFile     (void) noexcept;
    virtual             ~GpCompressorZipFile    (void) noexcept override final;

    virtual void        Compress                (std::u8string_view aPathIn,
                                                 std::u8string_view aFileOut) override final;
    virtual void        Decompress              (std::u8string_view aFileIn,
                                                 std::u8string_view aPathOut) override final;
};

}//namespace GPlatform
