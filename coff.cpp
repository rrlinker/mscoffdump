#include "coff.h"
#include "coffstr.h"

#include "vendor/wine/winnt.h"

#include <string>

using std::dec;
struct hexw {
    hexw(int width)
        : width(width)
    {}
    int width;
};

std::ostream& operator<<(std::ostream &os, hexw const &&h) {
    return os << std::hex << std::setw(h.width);
}

COFF::COFF(fs::path const &path) {
    file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    file.open(path);
}

void COFF::dump_all(std::ostream &os) {
    os << std::right << std::hex << std::setfill('0');

    IMAGE_FILE_HEADER fh;
    file.seekg(0, file.beg);
    file.read(reinterpret_cast<char*>(&fh), sizeof(fh));

    os << "IMAGE_FILE_HEADER\n"
       << " Machine              " << hexw(4) << fh.Machine              << " : " << coffstr::file_header_machine(fh.Machine) << '\n'
       << " NumberOfSections     " << dec     << fh.NumberOfSections     << '\n'
       << " TimeDateStamp        " << dec     << fh.TimeDateStamp        << '\n'
       << " PointerToSymbolTable " << hexw(8) << fh.PointerToSymbolTable << '\n'
       << " NumberOfSymbols      " << dec     << fh.NumberOfSymbols      << '\n'
       << " SizeOfOptionalHeader " << dec     << fh.SizeOfOptionalHeader << '\n'
       << " Characteristics      " << hexw(4) << fh.Characteristics      << '\n'
        ;
    for (auto chrt = fh.Characteristics; chrt; chrt &= chrt - 1) {
        os << "  - " << coffstr::file_header_characteristic(chrt & ~(chrt - 1)) << '\n';
    }
    os << '\n';

    for (DWORD i = 0; i < fh.NumberOfSections; i++) {
        IMAGE_SECTION_HEADER sh;
        file.read(reinterpret_cast<char*>(&sh), sizeof(sh));

        os << "IMAGE_SECTION_HEADER\n"
           << " Name                 "  << std::string((char const*)sh.Name, IMAGE_SIZEOF_SHORT_NAME) << '\n'
           << " PhysicalAddress      "  << hexw(8) << sh.Misc.PhysicalAddress << '\n'
           << " VirtualAddress       "  << hexw(8) << sh.VirtualAddress       << '\n'
           << " SizeOfRawData        "  << dec     << sh.SizeOfRawData        << '\n'
           << " PointerToRawData     "  << hexw(8) << sh.PointerToRawData     << '\n'
           << " PointerToRelocations "  << hexw(8) << sh.PointerToRelocations << '\n'
           << " PointerToLinenumbers "  << hexw(8) << sh.PointerToLinenumbers << '\n'
           << " NumberOfRelocations  "  << dec     << sh.NumberOfRelocations  << '\n'
           << " NumberOfLinenumbers  "  << dec     << sh.NumberOfLinenumbers  << '\n'
           << " Characteristics      "  << hexw(8) << sh.Characteristics      << '\n'
            ;
        for (auto chrt = sh.Characteristics & ~IMAGE_SCN_ALIGN_MASK; chrt; chrt &= chrt - 1) {
            os << "  - " << coffstr::section_header_characteristic(chrt & ~(chrt - 1)) << '\n';
        }
        os << "  - " << coffstr::section_header_characteristic_align(sh.Characteristics & IMAGE_SCN_ALIGN_MASK) << '\n';
        os << '\n';
    }
}

