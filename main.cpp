#include "coff.h"

#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main(int argc, char const *argv[]) {
    // cstdio shouldn't be used
    std::ios::sync_with_stdio(false);

    if (argc != 2) {
        char const *program = argc > 0 ? argv[0] : "mscoffdump";
        std::cerr << "usage: " << program << " file.obj\n"
            << "\tDumps specified Microsoft Common Object Format File."
            << std::endl;
        return 1;
    }

    try {
        auto path = fs::path(argv[1]);
        COFF coff(path);
        coff.dump_all(std::cout);
    } catch (std::exception const &e) {
        std::cerr << "Unexpected exception:\n\t" << e.what() << std::endl;
        return 2;
    }

    return 0;
}
