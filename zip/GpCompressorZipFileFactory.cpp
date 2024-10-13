#include <GpCompression/zip/GpCompressorZipFileFactory.hpp>
#include <GpCompression/zip/GpCompressorZipFile.hpp>

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

}// namespace GPlatform
