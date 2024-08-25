#pragma once

#include "../GpCompressor.hpp"

#if defined(__GNUC__)
  #ifndef _FILE_OFFSET_BITS
    #define _FILE_OFFSET_BITS 64
  #endif
  #ifndef _LARGEFILE64_SOURCE
    #define _LARGEFILE64_SOURCE 1
  #endif
#endif

#include <miniz/miniz.hpp>

namespace GPlatform {

class GpCompressorZip final: public GpCompressor
{
public:
    CLASS_REMOVE_CTRS_MOVE_COPY(GpCompressorZip)
    CLASS_DD(GpCompressorZip)

public:
                        GpCompressorZip     (void) noexcept;
    virtual             ~GpCompressorZip    (void) noexcept override final;

    virtual void        Close               (void) noexcept override final;
    virtual void        OpenFile            (std::string_view aFileName) override final;
    virtual void        CompressAndAdd      (std::string_view aPathOrFile) override final;

private:
    void                _Close              (void) noexcept;
    void                _AddFile            (std::string_view aFileNameInArchive,
                                             std::string_view aFileNameSrc);

private:
    mz_zip_archive      iZip;
    bool                iIsOpen = false;
    std::string         iFileName;
};

}// namespace GPlatform
