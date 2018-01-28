#pragma once

#include "vendor/wine/windef.h"

namespace coffstr {

    char const* file_header_machine(DWORD machine);
    char const* file_header_characteristic(DWORD chrt);

    char const* section_header_characteristic(DWORD chrt);
    char const* section_header_characteristic_align(DWORD chrt);

}

