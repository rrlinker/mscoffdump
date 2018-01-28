#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class COFF {
public:
    COFF(fs::path const &path);

    void dump_all(std::ostream &os);

private:
    std::ifstream file;
};

