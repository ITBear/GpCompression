#include "GpCompressorZip.hpp"

#include "../../GpCore2/GpUtils/Types/Strings/GpStringOps.hpp"

#include <filesystem>

namespace GPlatform {

GpCompressorZip::GpCompressorZip (void) noexcept
{
}

GpCompressorZip::~GpCompressorZip (void) noexcept
{
    _Close();
}

void    GpCompressorZip::Close (void) noexcept
{
    _Close();
}

void    GpCompressorZip::OpenFile (std::u8string_view aFileName)
{
    Close();

    mz_zip_zero_struct(&iZip);

    const std::u8string fileName(aFileName);

    const mz_bool zipInitRes = mz_zip_writer_init_file
    (
        &iZip,
        reinterpret_cast<const char*>(fileName.data()),
        0
    );

    THROW_COND_GP
    (
        zipInitRes == true,
        [&](){return u8"Failed to write zip file '"_sv + aFileName + u8"'"_sv;}
    );

    iFileName   = aFileName;
    iIsOpen     = true;
}

void    GpCompressorZip::CompressAndAdd (std::u8string_view aPathOrFile)
{
    THROW_COND_GP
    (
        iIsOpen == true,
        u8"Archive is not open"_sv
    );

    std::filesystem::path rootPath(aPathOrFile);

    if (std::filesystem::is_regular_file(rootPath))
    {
        _AddFile
        (
            rootPath.filename().u8string(),
            aPathOrFile
        );

        return;
    }

    for (const std::filesystem::directory_entry& pathIter: std::filesystem::recursive_directory_iterator(rootPath))
    {
        //Files list
        if (!std::filesystem::is_regular_file(pathIter.path()))
        {
            continue;
        }

        const std::filesystem::path& fullPath = pathIter.path();

        _AddFile
        (
            std::filesystem::relative(fullPath, rootPath).u8string(),
            fullPath.u8string()
        );
    }
}

void    GpCompressorZip::_Close (void) noexcept
{
    if (iIsOpen)
    {
        mz_zip_writer_finalize_archive(&iZip);
        mz_zip_writer_end(&iZip);
        iIsOpen = false;
    }
}

void    GpCompressorZip::_AddFile
(
    std::u8string_view aFileNameInArchive,
    std::u8string_view aFileNameSrc
)
{
    const std::u8string fileNameInArchive(aFileNameInArchive);
    const std::u8string fileNameSrc(aFileNameSrc);

    const mz_bool zipAddFileRes = mz_zip_writer_add_file
    (
        &iZip,
        reinterpret_cast<const char*>(fileNameInArchive.data()),
        reinterpret_cast<const char*>(fileNameSrc.data()),
        nullptr,
        0,
        MZ_BEST_COMPRESSION
    );

    THROW_COND_GP
    (
        zipAddFileRes == true,
        [&](){return u8"Failed to add file '"_sv + aFileNameSrc + u8"' to ZIP file '"_sv + iFileName + u8"'"_sv;}
    );
}

}//namespace GPlatform
