#pragma once

#include "vendor/wine/windef.h"

namespace coffstr {

    char const* file_header_machine(DWORD machine);
    char const* file_header_characteristic(DWORD chrt);

    char const* section_header_characteristic(DWORD chrt);
    char const* section_header_characteristic_align(DWORD chrt);

    char const* symbol_section_number(SHORT nb);
    char const* symbol_type(WORD type);
    char const* symbol_dtype(WORD type);
    char const* symbol_storage_class(BYTE cls);

}

