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
    std::string_view    /*aPathIn*/,
    std::string_view    /*aFileOut*/
)
{
    //TODO: implement
    THROW_GP_NOT_IMPLEMENTED();
}

void    GpCompressorZipFile::Decompress
(
    std::string_view    /*aFileIn*/,
    std::string_view    /*aPathOut*/
)
{
    //TODO: implement
    THROW_GP_NOT_IMPLEMENTED();
}

}// namespace GPlatform
