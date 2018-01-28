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
        file.seekg(IMAGE_SIZEOF_FILE_HEADER + i * IMAGE_SIZEOF_SECTION_HEADER, file.beg);
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

        if (sh.PointerToRelocations) {
            file.seekg(sh.PointerToRelocations, file.beg);
            for (DWORD j = 0; j < sh.NumberOfRelocations; j++) {
                IMAGE_RELOCATION rel;
                file.read(reinterpret_cast<char*>(&rel), sizeof(rel));

                os << " IMAGE_RELOCATION\n"
                   << "  VirtualAddress   " << hexw(8) << rel.VirtualAddress   << '\n'
                   << "  SymbolTableIndex " << dec     << rel.SymbolTableIndex << '\n'
                   ;
                os << "  Type             " << hexw(4) << rel.Type << " (" << coffstr::section_header_relocation_type(fh.Machine, rel.Type) << ")\n";
            }
            os << '\n';
        }
    }

    DWORD sizeof_string_table;
    file.seekg(fh.PointerToSymbolTable + fh.NumberOfSymbols * IMAGE_SIZEOF_SYMBOL, file.beg);
    file.read(reinterpret_cast<char*>(&sizeof_string_table), sizeof(sizeof_string_table));
    std::vector<char> string_table(sizeof_string_table);
    file.seekg(-sizeof(sizeof_string_table), file.cur);
    file.read(string_table.data(), sizeof_string_table);

    file.seekg(fh.PointerToSymbolTable, file.beg);
    for (DWORD i = 0; i < fh.NumberOfSymbols; i++) {
        IMAGE_SYMBOL sym;
        file.seekg(fh.PointerToSymbolTable + i * IMAGE_SIZEOF_SYMBOL);
        file.read(reinterpret_cast<char*>(&sym), sizeof(sym));

        os << "IMAGE_SYMBOL\n";
        if (sym.N.Name.Short) {
        os << " Name               " << std::string((char const*)sym.N.ShortName, sizeof(sym.N.ShortName)) << '\n';
        } else {
        os << " Name               " << hexw(8) << sym.N.Name.Long << " : " << &string_table[sym.N.Name.Long] << '\n';
        }
        os << " Value              " << hexw(8) << sym.Value << '\n';
        os << " SectionNumber      " << dec     << sym.SectionNumber;
        if (sym.SectionNumber <= 0)
            os << " (" << coffstr::symbol_section_number(sym.SectionNumber) << ')';
        os << '\n';
        os << " Type               " << hexw(8) << sym.Type << " : " << coffstr::symbol_type(sym.Type) << ' ' << coffstr::symbol_dtype(sym.Type) << '\n';
        os << " StorageClass       " << hexw(8) << (DWORD)sym.StorageClass << " : " << coffstr::symbol_storage_class(sym.StorageClass) << '\n';
        os << " NumberOfAuxSymbols " << dec     << (DWORD)sym.NumberOfAuxSymbols << '\n'
           << '\n';

        // Skip AUX symbols
        i += sym.NumberOfAuxSymbols;
    }
}

