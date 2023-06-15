#include "GpDecompressorZipFactory.hpp"
#include "GpDecompressorZip.hpp"

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

}//namespace GPlatform
