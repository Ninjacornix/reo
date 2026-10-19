#include "guard_generated_source.hpp"
#include <fstream>
#include <iterator>
#include <iostream>
int main(int argc, char** argv) {
    try {
        if (argc < 3)
            return 2;
        std::ifstream input(argv[1]);
        if (!input)
            return 3;
        std::string source((std::istreambuf_iterator<char>(input)), {});
        std::ofstream output(argv[2]);
        if (!output)
            return 4;
        output << ps2recomp::source_guard::instrument(source, argc < 4);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
