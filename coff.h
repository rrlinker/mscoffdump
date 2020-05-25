#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>

class COFF {
public:
    COFF(std::filesystem::path const &path);

    void dump_all(std::ostream &os);

private:
    std::ifstream file;
};

