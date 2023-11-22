TEMPLATE        = lib
#CONFIG         += staticlib
VER_MAJ		    = 2
VER_MIN		    = 1
VER_PAT		    = 4
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=1ddd3348-8817-469b-0b75-a9784d030570
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
DEFINES		   += GP_COMPRESSION_LIBRARY
PACKET_NAME     = GpCompression
DIR_LEVEL       = ./..

include(../../QtGlobalPro.pri)

#------------------------------ LIBS BEGIN ---------------------------------
os_windows{
}

os_linux{
}
#------------------------------- LIBS END ----------------------------------

SOURCES += \
    zip/GpCompressorZip.cpp \
    zip/GpCompressorZipFactory.cpp \
    zip/GpCompressorZipFile.cpp \
    zip/GpCompressorZipFileFactory.cpp \
    zip/GpDecompressorZip.cpp \
    zip/GpDecompressorZipFactory.cpp

HEADERS += \
    GpCompression_global.hpp \
    GpCompressor.hpp \
    GpCompressorFactory.hpp \
    GpCompressorFile.hpp \
    GpCompressorFileFactory.hpp \
    GpCompressorStream.hpp \
    GpCompressorStreamFactory.hpp \
    GpDecompressor.hpp \
    GpDecompressorFactory.hpp \
    zip/GpCompressorZip.hpp \
    zip/GpCompressorZipFactory.hpp \
    zip/GpCompressorZipFile.hpp \
    zip/GpCompressorZipFileFactory.hpp \
    zip/GpDecompressorZip.hpp \
    zip/GpDecompressorZipFactory.hpp \
    zip/GpZip.hpp
