#include <GpCompression/zip/GpCompressorZip.hpp>
#include <GpCore2/GpUtils/Types/Strings/GpStringOps.hpp>

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

void    GpCompressorZip::OpenFile (std::string_view aFileName)
{
    Close();

    mz_zip_zero_struct(&iZip);

    const std::string fileName(aFileName);

    const mz_bool zipInitRes = mz_zip_writer_init_file
    (
        &iZip,
        reinterpret_cast<const char*>(std::data(fileName)),
        0
    );

    THROW_COND_GP
    (
        zipInitRes == static_cast<decltype(zipInitRes)>(true),
        [&](){return "Failed to write zip file '"_sv + aFileName + "'"_sv;}
    );

    iFileName   = aFileName;
    iIsOpen     = true;
}

void    GpCompressorZip::CompressAndAdd (std::string_view aPathOrFile)
{
    THROW_COND_GP
    (
        iIsOpen == true,
        "Archive is not open"_sv
    );

    std::filesystem::path rootPath(aPathOrFile);

    if (std::filesystem::is_regular_file(rootPath))
    {
        _AddFile
        (
            rootPath.filename().string(),
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
            std::filesystem::relative(fullPath, rootPath).string(),
            fullPath.string()
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
    std::string_view aFileNameInArchive,
    std::string_view aFileNameSrc
)
{
    const std::string fileNameInArchive(aFileNameInArchive);
    const std::string fileNameSrc(aFileNameSrc);

    const mz_bool zipAddFileRes = mz_zip_writer_add_file
    (
        &iZip,
        reinterpret_cast<const char*>(std::data(fileNameInArchive)),
        reinterpret_cast<const char*>(std::data(fileNameSrc)),
        nullptr,
        0,
        MZ_BEST_COMPRESSION
    );

    THROW_COND_GP
    (
        zipAddFileRes == static_cast<decltype(zipAddFileRes)>(true),
        [&]()
        {
            return fmt::format
            (
                "Failed to add file '{}' to ZIP file '{}'",
                aFileNameSrc,
                iFileName
            );
        }
    );
}

}// namespace GPlatform
