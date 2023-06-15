#include "GpCompressorZipFile.hpp"

namespace GPlatform {

GpCompressorZipFile::GpCompressorZipFile (void) noexcept
{
}

GpCompressorZipFile::~GpCompressorZipFile (void) noexcept
{
}

void    GpCompressorZipFile::Compress
(
    std::u8string_view  /*aPathIn*/,
    std::u8string_view  /*aFileOut*/
)
{
    //TODO: implement
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpCompressorZipFile::Decompress
(
    std::u8string_view  /*aFileIn*/,
    std::u8string_view  /*aPathOut*/
)
{
    //TODO: implement
    THROW_GP_NOT_IMPLEMENTED();
}

}//namespace GPlatform
