#pragma once

#include "../GpCore2/GpUtils/Macro/GpMacroImportExport.hpp"

#if defined(GP_COMPRESSION_LIBRARY)
    #define GP_COMPRESSION_API GP_DECL_EXPORT
#else
    #define GP_COMPRESSION_API GP_DECL_IMPORT
#endif
