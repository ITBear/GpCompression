# ----------- Config -----------
TEMPLATE        = lib
QMAKE_CXXFLAGS += -DGP_REFLECTION_STATIC_ADD_TO_MANAGER
QMAKE_CXXFLAGS += -DGP_MODULE_UUID=1ddd3348-8817-469b-0b75-a9784d030570
PACKET_NAME     = GpCompression
DEFINES        += GP_COMPRESSION_LIBRARY
_VER_MAJ        = 2
_VER_MIN        = 1
_VER_PAT        = 6
DIR_LEVEL       = ./..

include($$DIR_LEVEL/../QtGlobalPro.pri)

equals(var_link, "static") {
	CONFIG += staticlib
}

# ----------- Libraries -----------
equals(var_os, "windows") {
	LIBS += -lGpUtils$$TARGET_POSTFIX

	LIBS += -lminiz
}

equals(var_os, "linux") {
	LIBS += -lGpUtils$$TARGET_POSTFIX

	LIBS += -lminiz
	LIBS += -lfmt
}

# ----------- Sources and headers -----------
SOURCES += \
    GpCompressionLib.cpp \
    zip/GpCompressorZip.cpp \
    zip/GpCompressorZipFactory.cpp \
    zip/GpCompressorZipFile.cpp \
    zip/GpCompressorZipFileFactory.cpp \
    zip/GpDecompressorZip.cpp \
    zip/GpDecompressorZipFactory.cpp

HEADERS += \
    GpCompressionLib.hpp \
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
    zip/GpDecompressorZipFactory.hpp
