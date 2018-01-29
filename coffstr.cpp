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

char const* symbol_section_number(SHORT nb) {
    switch (nb) {
        case IMAGE_SYM_UNDEFINED : return "UNDEFINED";
        case IMAGE_SYM_ABSOLUTE  : return "ABSOLUTE";
        case IMAGE_SYM_DEBUG     : return "DEBUG";
    }
    return "";
}

char const* symbol_type(WORD type) {
    type = BTYPE(type);
    switch (type) {
        case IMAGE_SYM_TYPE_NULL   : return "NULL";
        case IMAGE_SYM_TYPE_VOID   : return "VOID";
        case IMAGE_SYM_TYPE_CHAR   : return "CHAR";
        case IMAGE_SYM_TYPE_SHORT  : return "SHORT";
        case IMAGE_SYM_TYPE_INT    : return "INT";
        case IMAGE_SYM_TYPE_LONG   : return "LONG";
        case IMAGE_SYM_TYPE_FLOAT  : return "FLOAT";
        case IMAGE_SYM_TYPE_DOUBLE : return "DOUBLE";
        case IMAGE_SYM_TYPE_STRUCT : return "STRUCT";
        case IMAGE_SYM_TYPE_UNION  : return "UNION";
        case IMAGE_SYM_TYPE_ENUM   : return "ENUM";
        case IMAGE_SYM_TYPE_MOE    : return "MOE";
        case IMAGE_SYM_TYPE_BYTE   : return "BYTE";
        case IMAGE_SYM_TYPE_WORD   : return "WORD";
        case IMAGE_SYM_TYPE_UINT   : return "UINT";
        case IMAGE_SYM_TYPE_DWORD  : return "DWORD";
        case IMAGE_SYM_TYPE_PCODE  : return "PCODE";
    }
    return "";
}

char const* symbol_dtype(WORD type) {
    type = (type & N_TMASK) >> N_BTSHFT;
    switch (type) {
        case IMAGE_SYM_DTYPE_NULL     : return "NULL";
        case IMAGE_SYM_DTYPE_POINTER  : return "POINTER";
        case IMAGE_SYM_DTYPE_FUNCTION : return "FUNCTION";
        case IMAGE_SYM_DTYPE_ARRAY    : return "ARRAY";
    }
    return "";
}

char const* symbol_storage_class(BYTE cls) {
    switch (cls) {
        case IMAGE_SYM_CLASS_END_OF_FUNCTION  : return "END_OF_FUNCTION";
        case IMAGE_SYM_CLASS_NULL             : return "NULL";
        case IMAGE_SYM_CLASS_AUTOMATIC        : return "AUTOMATIC";
        case IMAGE_SYM_CLASS_EXTERNAL         : return "EXTERNAL";
        case IMAGE_SYM_CLASS_STATIC           : return "STATIC";
        case IMAGE_SYM_CLASS_REGISTER         : return "REGISTER";
        case IMAGE_SYM_CLASS_EXTERNAL_DEF     : return "EXTERNAL_DEF";
        case IMAGE_SYM_CLASS_LABEL            : return "LABEL";
        case IMAGE_SYM_CLASS_UNDEFINED_LABEL  : return "UNDEFINED_LABEL";
        case IMAGE_SYM_CLASS_MEMBER_OF_STRUCT : return "MEMBER_OF_STRUCT";
        case IMAGE_SYM_CLASS_ARGUMENT         : return "ARGUMENT";
        case IMAGE_SYM_CLASS_STRUCT_TAG       : return "STRUCT_TAG";
        case IMAGE_SYM_CLASS_MEMBER_OF_UNION  : return "MEMBER_OF_UNION";
        case IMAGE_SYM_CLASS_UNION_TAG        : return "UNION_TAG";
        case IMAGE_SYM_CLASS_TYPE_DEFINITION  : return "TYPE_DEFINITION";
        case IMAGE_SYM_CLASS_UNDEFINED_STATIC : return "UNDEFINED_STATIC";
        case IMAGE_SYM_CLASS_ENUM_TAG         : return "ENUM_TAG";
        case IMAGE_SYM_CLASS_MEMBER_OF_ENUM   : return "MEMBER_OF_ENUM";
        case IMAGE_SYM_CLASS_REGISTER_PARAM   : return "REGISTER_PARAM";
        case IMAGE_SYM_CLASS_BIT_FIELD        : return "BIT_FIELD";
        case IMAGE_SYM_CLASS_FAR_EXTERNAL     : return "FAR_EXTERNAL";
        case IMAGE_SYM_CLASS_BLOCK            : return "BLOCK";
        case IMAGE_SYM_CLASS_FUNCTION         : return "FUNCTION";
        case IMAGE_SYM_CLASS_END_OF_STRUCT    : return "END_OF_STRUCT";
        case IMAGE_SYM_CLASS_FILE             : return "FILE";
        case IMAGE_SYM_CLASS_SECTION          : return "SECTION";
        case IMAGE_SYM_CLASS_WEAK_EXTERNAL    : return "WEAK_EXTERNAL";
    }
    return "UNKNOWN";
}

char const* section_header_relocation_type(WORD machine, WORD type) {
    switch (machine) {
        case IMAGE_FILE_MACHINE_I386: return section_header_relocation_type_i386(type);
        case IMAGE_FILE_MACHINE_AMD64: return section_header_relocation_type_amd64(type);
    }
    return "UNKNOWN";
}

char const* section_header_relocation_type_i386(WORD type) {
    switch (type) {
        case IMAGE_REL_I386_ABSOLUTE : return "ABSOLUTE";
        case IMAGE_REL_I386_DIR16    : return "DIR16";
        case IMAGE_REL_I386_REL16    : return "REL16";
        case IMAGE_REL_I386_DIR32    : return "DIR32";
        case IMAGE_REL_I386_DIR32NB  : return "DIR32NB";
        case IMAGE_REL_I386_SEG12    : return "SEG12";
        case IMAGE_REL_I386_SECTION  : return "SECTION";
        case IMAGE_REL_I386_SECREL   : return "SECREL";
        case IMAGE_REL_I386_TOKEN    : return "TOKEN";
        case IMAGE_REL_I386_SECREL7  : return "SECREL7";
        case IMAGE_REL_I386_REL32    : return "REL32";
    }
    return "UNKNOWN";
}

char const* section_header_relocation_type_amd64(WORD type) {
    switch (type) {
        case IMAGE_REL_AMD64_ABSOLUTE : return "ABSOLUTE";
        case IMAGE_REL_AMD64_ADDR64   : return "ADDR64";
        case IMAGE_REL_AMD64_ADDR32   : return "ADDR32";
        case IMAGE_REL_AMD64_ADDR32NB : return "ADDR32NB";
        case IMAGE_REL_AMD64_REL32    : return "REL32";
        case IMAGE_REL_AMD64_REL32_1  : return "REL32_1";
        case IMAGE_REL_AMD64_REL32_2  : return "REL32_2";
        case IMAGE_REL_AMD64_REL32_3  : return "REL32_3";
        case IMAGE_REL_AMD64_REL32_4  : return "REL32_4";
        case IMAGE_REL_AMD64_REL32_5  : return "REL32_5";
        case IMAGE_REL_AMD64_SECTION  : return "SECTION";
        case IMAGE_REL_AMD64_SECREL   : return "SECREL";
        case IMAGE_REL_AMD64_SECREL7  : return "SECREL7";
        case IMAGE_REL_AMD64_TOKEN    : return "TOKEN";
        case IMAGE_REL_AMD64_SREL32   : return "SREL32";
        case IMAGE_REL_AMD64_PAIR     : return "PAIR";
        case IMAGE_REL_AMD64_SSPAN32  : return "SSPAN32";
    }
    return "UNKNOWN";
}

}

