#pragma once

#include "../GpCompressorFactory.hpp"
#include "../GpCompression_global.hpp"

namespace GPlatform {

class GP_COMPRESSION_API GpCompressorZipFactory final: public GpCompressorFactory
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorZipFactory)
    CLASS_DD(GpCompressorZipFactory)

public:
                                    GpCompressorZipFactory  (void) noexcept;
    virtual                         ~GpCompressorZipFactory (void) noexcept override final;

    virtual GpCompressor::SP        NewInstance             (void) override final;
};

}// namespace GPlatform
