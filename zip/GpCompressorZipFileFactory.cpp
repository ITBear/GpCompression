#include "GpCompressorZipFileFactory.hpp"
#include "GpCompressorZipFile.hpp"

namespace GPlatform {

GpCompressorZipFileFactory::GpCompressorZipFileFactory (void) noexcept
{
}

GpCompressorZipFileFactory::~GpCompressorZipFileFactory (void) noexcept
{
}

GpCompressorFile::SP    GpCompressorZipFileFactory::NewInstance (void)
{
    return MakeSP<GpCompressorZipFile>();
}

}//namespace GPlatform
