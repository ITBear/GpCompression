#include <GpCompression/zip/GpDecompressorZipFactory.hpp>
#include <GpCompression/zip/GpDecompressorZip.hpp>

namespace GPlatform {

GpDecompressorZipFactory::GpDecompressorZipFactory (void) noexcept
{
}

GpDecompressorZipFactory::~GpDecompressorZipFactory (void) noexcept
{
}

GpDecompressor::SP  GpDecompressorZipFactory::NewInstance (void)
{
    return MakeSP<GpDecompressorZip>();
}

}// namespace GPlatform
