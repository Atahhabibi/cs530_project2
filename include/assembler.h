#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

class Assembler {
private:
    std::unordered_map<std::string, int> SYMTAB;  // Symbol Table
    int LOCCTR;  // Location Counter
    int START_ADDRESS;  // Start address

public:
    Assembler() : LOCCTR(0), START_ADDRESS(0) {}

    void pass1(const std::string& filename);
    void pass2(const std::string& filename);
};

#endif
