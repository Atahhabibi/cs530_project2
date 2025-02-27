#include "../include/assembler.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./essy <source1.sic> <source2.sic>\n";
        return 1;
    }

    Assembler assembler;
    for (int i = 1; i < argc; ++i) {
        assembler.pass1(argv[i]);
        assembler.pass2(argv[i]);
    }

    return 0;
}
