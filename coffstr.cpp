#include "coffstr.h"

namespace coffstr {

char const* file_header_machine(DWORD machine) {
    switch (machine) {
        case IMAGE_FILE_MACHINE_I860      : return "I860";
        case IMAGE_FILE_MACHINE_I386      : return "I386";
        case IMAGE_FILE_MACHINE_R3000     : return "R3000";
        case IMAGE_FILE_MACHINE_R4000     : return "R4000";
        case IMAGE_FILE_MACHINE_R10000    : return "R10000";
        case IMAGE_FILE_MACHINE_WCEMIPSV2 : return "WCEMIPSV2";
        case IMAGE_FILE_MACHINE_ALPHA     : return "ALPHA";
        case IMAGE_FILE_MACHINE_SH3       : return "SH3";
        case IMAGE_FILE_MACHINE_SH3DSP    : return "SH3DSP";
        case IMAGE_FILE_MACHINE_SH3E      : return "SH3E";
        case IMAGE_FILE_MACHINE_SH4       : return "SH4";
        case IMAGE_FILE_MACHINE_SH5       : return "SH5";
        case IMAGE_FILE_MACHINE_ARM       : return "ARM";
        case IMAGE_FILE_MACHINE_THUMB     : return "THUMB";
        case IMAGE_FILE_MACHINE_ARMNT     : return "ARMNT";
        case IMAGE_FILE_MACHINE_ARM64     : return "ARM64";
        case IMAGE_FILE_MACHINE_AM33      : return "AM33";
        case IMAGE_FILE_MACHINE_POWERPC   : return "POWERPC";
        case IMAGE_FILE_MACHINE_POWERPCFP : return "POWERPCFP";
        case IMAGE_FILE_MACHINE_IA64      : return "IA64";
        case IMAGE_FILE_MACHINE_MIPS16    : return "MIPS16";
        case IMAGE_FILE_MACHINE_ALPHA64   : return "ALPHA64";
        case IMAGE_FILE_MACHINE_MIPSFPU   : return "MIPSFPU";
        case IMAGE_FILE_MACHINE_MIPSFPU16 : return "MIPSFPU16";
        case IMAGE_FILE_MACHINE_TRICORE   : return "TRICORE";
        case IMAGE_FILE_MACHINE_CEF       : return "CEF";
        case IMAGE_FILE_MACHINE_EBC       : return "EBC";
        case IMAGE_FILE_MACHINE_AMD64     : return "AMD64";
        case IMAGE_FILE_MACHINE_M32R      : return "M32R";
        case IMAGE_FILE_MACHINE_CEE       : return "CEE";
    }
    return "UNKNOWN";
}

char const* file_header_characteristic(DWORD chrt) {
    switch (chrt) {
        case IMAGE_FILE_RELOCS_STRIPPED         : return "RELOCS_STRIPPED";
        case IMAGE_FILE_EXECUTABLE_IMAGE        : return "EXECUTABLE_IMAGE";
        case IMAGE_FILE_LINE_NUMS_STRIPPED      : return "LINE_NUMS_STRIPPED";
        case IMAGE_FILE_LOCAL_SYMS_STRIPPED     : return "LOCAL_SYMS_STRIPPED";
        case IMAGE_FILE_AGGRESIVE_WS_TRIM       : return "AGGRESIVE_WS_TRIM";
        case IMAGE_FILE_LARGE_ADDRESS_AWARE     : return "LARGE_ADDRESS_AWARE";
        case IMAGE_FILE_16BIT_MACHINE           : return "16BIT_MACHINE";
        case IMAGE_FILE_BYTES_REVERSED_LO       : return "BYTES_REVERSED_LO";
        case IMAGE_FILE_32BIT_MACHINE           : return "32BIT_MACHINE";
        case IMAGE_FILE_DEBUG_STRIPPED          : return "DEBUG_STRIPPED";
        case IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP : return "REMOVABLE_RUN_FROM_SWAP";
        case IMAGE_FILE_NET_RUN_FROM_SWAP       : return "NET_RUN_FROM_SWAP";
        case IMAGE_FILE_SYSTEM                  : return "SYSTEM";
        case IMAGE_FILE_DLL                     : return "DLL";
        case IMAGE_FILE_UP_SYSTEM_ONLY          : return "UP_SYSTEM_ONLY";
        case IMAGE_FILE_BYTES_REVERSED_HI       : return "BYTES_REVERSED_HI";
    }
    return "";
}

char const* section_header_characteristic(DWORD chrt) {
    switch (chrt) {
        // case IMAGE_SCN_TYPE_REG               : return "TYPE_REG";
        // case IMAGE_SCN_TYPE_DSECT             : return "TYPE_DSECT";
        // case IMAGE_SCN_TYPE_NOLOAD            : return "TYPE_NOLOAD";
        // case IMAGE_SCN_TYPE_GROUP             : return "TYPE_GROUP";
        case IMAGE_SCN_TYPE_NO_PAD            : return "TYPE_NO_PAD";
        //case IMAGE_SCN_TYPE_COPY              : return "TYPE_COPY";
        case IMAGE_SCN_CNT_CODE               : return "CNT_CODE";
        case IMAGE_SCN_CNT_INITIALIZED_DATA   : return "CNT_INITIALIZED_DATA";
        case IMAGE_SCN_CNT_UNINITIALIZED_DATA : return "CNT_UNINITIALIZED_DATA";
        case IMAGE_SCN_LNK_OTHER              : return "LNK_OTHER";
        case IMAGE_SCN_LNK_INFO               : return "LNK_INFO";
        //case IMAGE_SCN_TYPE_OVER              : return "TYPE_OVER";
        case IMAGE_SCN_LNK_REMOVE             : return "LNK_REMOVE";
        case IMAGE_SCN_LNK_COMDAT             : return "LNK_COMDAT";
        //case IMAGE_SCN_MEM_PROTECTED          : return "MEM_PROTECTED";
        case IMAGE_SCN_MEM_FARDATA            : return "MEM_FARDATA";
        //case IMAGE_SCN_MEM_SYSHEAP            : return "MEM_SYSHEAP";
        case IMAGE_SCN_MEM_PURGEABLE          : return "MEM_PURGEABLE";
        //case IMAGE_SCN_MEM_16BIT              : return "MEM_16BIT";
        case IMAGE_SCN_MEM_LOCKED             : return "MEM_LOCKED";
        case IMAGE_SCN_MEM_PRELOAD            : return "MEM_PRELOAD";
        case IMAGE_SCN_LNK_NRELOC_OVFL        : return "LNK_NRELOC_OVFL";
        case IMAGE_SCN_MEM_DISCARDABLE        : return "MEM_DISCARDABLE";
        case IMAGE_SCN_MEM_NOT_CACHED         : return "MEM_NOT_CACHED";
        case IMAGE_SCN_MEM_NOT_PAGED          : return "MEM_NOT_PAGED";
        case IMAGE_SCN_MEM_SHARED             : return "MEM_SHARED";
        case IMAGE_SCN_MEM_EXECUTE            : return "MEM_EXECUTE";
        case IMAGE_SCN_MEM_READ               : return "MEM_READ";
        case IMAGE_SCN_MEM_WRITE              : return "MEM_WRITE";
    }
    return "";
}

char const* section_header_characteristic_align(DWORD align) {
    switch (align) {
        case IMAGE_SCN_ALIGN_1BYTES    : return "ALIGN_1BYTES";
        case IMAGE_SCN_ALIGN_2BYTES    : return "ALIGN_2BYTES";
        case IMAGE_SCN_ALIGN_4BYTES    : return "ALIGN_4BYTES";
        case IMAGE_SCN_ALIGN_8BYTES    : return "ALIGN_8BYTES";
        case IMAGE_SCN_ALIGN_16BYTES   : return "ALIGN_16BYTES";
        case IMAGE_SCN_ALIGN_32BYTES   : return "ALIGN_32BYTES";
        case IMAGE_SCN_ALIGN_64BYTES   : return "ALIGN_64BYTES";
        case IMAGE_SCN_ALIGN_128BYTES  : return "ALIGN_128BYTES";
        case IMAGE_SCN_ALIGN_256BYTES  : return "ALIGN_256BYTES";
        case IMAGE_SCN_ALIGN_512BYTES  : return "ALIGN_512BYTES";
        case IMAGE_SCN_ALIGN_1024BYTES : return "ALIGN_1024BYTES";
        case IMAGE_SCN_ALIGN_2048BYTES : return "ALIGN_2048BYTES";
        case IMAGE_SCN_ALIGN_4096BYTES : return "ALIGN_4096BYTES";
        case IMAGE_SCN_ALIGN_8192BYTES : return "ALIGN_8192BYTES";
    }
    return "";
}

}

