#pragma once

#ifdef _WIN32
#include <Windows.h>
#else
#include "vendor/wine/windef.h"
#endif

namespace coffstr {

    char const* file_header_machine(DWORD machine);
    char const* file_header_characteristic(DWORD chrt);

    char const* section_header_characteristic(DWORD chrt);
    char const* section_header_characteristic_align(DWORD chrt);
    char const* section_header_relocation_type(WORD machine, WORD type);
    char const* section_header_relocation_type_i386(WORD type);
    char const* section_header_relocation_type_amd64(WORD type);

    char const* symbol_section_number(SHORT nb);
    char const* symbol_type(WORD type);
    char const* symbol_dtype(WORD type);
    char const* symbol_storage_class(BYTE cls);

}

