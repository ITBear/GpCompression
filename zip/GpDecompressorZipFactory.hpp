#pragma once

#include <GpCompression/GpDecompressorFactory.hpp>

namespace GPlatform {

class GP_COMPRESSION_API GpDecompressorZipFactory final: public GpDecompressorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpDecompressorZipFactory)
    CLASS_DD(GpDecompressorZipFactory)

public:
                                    GpDecompressorZipFactory    (void) noexcept;
    virtual                         ~GpDecompressorZipFactory   (void) noexcept override final;

    virtual GpDecompressor::SP      NewInstance                 (void) override final;
};

}// namespace GPlatform
