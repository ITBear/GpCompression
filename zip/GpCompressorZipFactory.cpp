#include <GpCompression/zip/GpCompressorZipFactory.hpp>
#include <GpCompression/zip/GpCompressorZip.hpp>

namespace GPlatform {

GpCompressorZipFactory::GpCompressorZipFactory (void) noexcept
{
}

GpCompressorZipFactory::~GpCompressorZipFactory (void) noexcept
{
}

GpCompressor::SP    GpCompressorZipFactory::NewInstance (void)
{
    return MakeSP<GpCompressorZip>();
}

}// namespace GPlatform
