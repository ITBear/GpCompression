#pragma once

#include <GpCompression/GpCompressorFileFactory.hpp>

namespace GPlatform {

class GP_COMPRESSION_API GpCompressorZipFileFactory final: public GpCompressorFileFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorZipFileFactory)
    CLASS_DD(GpCompressorZipFileFactory)

public:
                                    GpCompressorZipFileFactory  (void) noexcept;
    virtual                         ~GpCompressorZipFileFactory (void) noexcept override final;

    virtual GpCompressorFile::SP    NewInstance                 (void) override final;
};

}// namespace GPlatform
