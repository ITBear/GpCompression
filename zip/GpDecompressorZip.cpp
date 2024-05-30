#include "GpDecompressorZip.hpp"

#include <GpCore2/GpUtils/Types/Strings/GpStringOps.hpp>

namespace GPlatform {

GpDecompressorZip::GpDecompressorZip (void) noexcept
{
}

GpDecompressorZip::~GpDecompressorZip (void) noexcept
{
    _Close();
}

void    GpDecompressorZip::Close (void) noexcept
{
    _Close();
}

void    GpDecompressorZip::OpenFile (std::string_view aFileName)
{
    Close();

    mz_zip_zero_struct(&iZip);

    const std::string fileName(aFileName);

    const mz_bool zipInitRes = mz_zip_reader_init_file
    (
        &iZip,
        reinterpret_cast<const char*>(std::data(fileName)),
        0
    );

    THROW_COND_GP
    (
        zipInitRes == static_cast<decltype(zipInitRes)>(true),
        [&](){return "Failed to read zip file '"_sv + aFileName + "'"_sv;}
    );

    iFileName   = aFileName;
    iIsOpen     = true;
}

size_t  GpDecompressorZip::ElementsCount (void) const
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    const mz_uint filesCount = mz_zip_reader_get_num_files(const_cast<mz_zip_archive*>(&iZip));
    return NumOps::SConvert<size_t>(filesCount);
}

std::string GpDecompressorZip::ElementName (const size_t aElementId) const
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    const mz_zip_archive_file_stat stat = _FileStat(aElementId);
    return std::string(stat.m_filename);
}

GpBytesArray    GpDecompressorZip::DecompressElement (const size_t aElementId) const
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    const mz_zip_archive_file_stat stat = _FileStat(aElementId);

    return _Decompress(stat);
}

GpBytesArray    GpDecompressorZip::DecompressElement (std::string_view aElementName) const
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    const std::string fileName(aElementName);

    const int elementId = mz_zip_reader_locate_file
    (
        const_cast<mz_zip_archive*>(&iZip),
        reinterpret_cast<const char*>(std::data(fileName)),
        nullptr,
        MZ_ZIP_FLAG_CASE_SENSITIVE
    );

    THROW_COND_GP
    (
        elementId >= 0,
        [&](){return "File '"_sv + aElementName + "' not found in zip archive '"_sv + iFileName + "'"_sv;}
    );

    return DecompressElement(NumOps::SConvert<size_t>(elementId));
}

void    GpDecompressorZip::_Close (void) noexcept
{
    if (iIsOpen)
    {
        mz_zip_reader_end(&iZip);
        iIsOpen = false;
    }
}

mz_zip_archive_file_stat    GpDecompressorZip::_FileStat (const size_t aElementId) const
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    mz_zip_archive_file_stat stat;

    const mz_bool res =
    mz_zip_reader_file_stat
    (
        const_cast<mz_zip_archive*>(&iZip),
        NumOps::SConvert<mz_uint>(aElementId),
        &stat
    );

    THROW_COND_GP
    (
        res == static_cast<decltype(res)>(true),
        [&]()
        {
            return fmt::format
            (
                "Failed to read zip info element {}, zip file '{}'",
                aElementId,
                iFileName
            );
        }
    );

    return stat;
}

GpBytesArray    GpDecompressorZip::_Decompress (const mz_zip_archive_file_stat& aStat) const
{
    GpBytesArray extractedData;
    extractedData.resize(NumOps::SConvert<size_t>(aStat.m_uncomp_size));

    const mz_bool extractRes = mz_zip_reader_extract_file_to_mem
    (
        const_cast<mz_zip_archive*>(&iZip),
        aStat.m_filename,
        std::data(extractedData),
        NumOps::SConvert<size_t>(aStat.m_uncomp_size),
        0
    );

    THROW_COND_GP
    (
        extractRes == static_cast<decltype(extractRes)>(true),
        [&]()
        {
            return fmt::format
            (
                "Failed to extract file '{}', from zip file '{}'",
                aStat.m_filename,
                iFileName
            );
        }
    );

    return extractedData;
}

}// namespace GPlatform
