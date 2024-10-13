#pragma once

#include <GpCompression/GpDecompressor.hpp>

#if defined(__GNUC__)
  #ifndef _FILE_OFFSET_BITS
    #define _FILE_OFFSET_BITS 64
  #endif
  #ifndef _LARGEFILE64_SOURCE
    #define _LARGEFILE64_SOURCE 1
  #endif
#endif

#include <miniz/miniz.h>

namespace GPlatform {

class GpDecompressorZip final: public GpDecompressor
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpDecompressorZip)
    CLASS_DD(GpDecompressorZip)

public:
                                GpDecompressorZip   (void) noexcept;
    virtual                     ~GpDecompressorZip  (void) noexcept override final;

    virtual void                Close               (void) noexcept override final;
    virtual void                OpenFile            (std::string_view aFileName) override final;
    virtual size_t              ElementsCount       (void) const override final;
    virtual std::string         ElementName         (size_t aElementId) const override final;
    virtual GpBytesArray        DecompressElement   (size_t aElementId) const override final;
    virtual GpBytesArray        DecompressElement   (std::string_view aElementName) const override final;
    //virtual void              DecompressElement   (std::string_view aOutFileName) const override final;

private:
    void                        _Close              (void) noexcept;
    mz_zip_archive_file_stat    _FileStat           (size_t aElementId) const;
    GpBytesArray                _Decompress         (const mz_zip_archive_file_stat& aStat) const;

private:
    mz_zip_archive              iZip;
    bool                        iIsOpen = false;
    std::string                 iFileName;
};

}// namespace GPlatform
