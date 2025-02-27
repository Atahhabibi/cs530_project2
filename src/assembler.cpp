#include "../include/assembler.h"

void Assembler::pass1(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    std::ofstream symtabFile(filename + ".st");  // Output SYMTAB file
    if (!symtabFile) {
        std::cerr << "Error: Cannot create symbol table file\n";
        return;
    }

    std::string line, label, opcode, operand;
    bool firstLine = true;
    LOCCTR = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> label >> opcode >> operand;

        // Handle START directive
        if (firstLine && opcode == "START") {
            START_ADDRESS = std::stoi(operand, nullptr, 16);
            LOCCTR = START_ADDRESS;
            firstLine = false;
            continue;
        }

        // If a label exists, store it in SYMTAB
        if (!label.empty()) {
            if (SYMTAB.find(label) != SYMTAB.end()) {
                std::cerr << "Error: Duplicate symbol found: " << label << "\n";
                return;
            }
            SYMTAB[label] = LOCCTR;
            symtabFile << label << " " << std::hex << LOCCTR << "\n";
        }

        // Increment LOCCTR based on instruction type
        if (opcode == "WORD") {
            LOCCTR += 3;
        } else if (opcode == "RESW") {
            LOCCTR += 3 * std::stoi(operand);
        } else if (opcode == "RESB") {
            LOCCTR += std::stoi(operand);
        } else if (opcode == "BYTE") {
            if (operand[0] == 'C') {
                LOCCTR += operand.length() - 3;  // Count character length
            } else {
                LOCCTR += (operand.length() - 3) / 2;  // Hex representation
            }
        } else {
            LOCCTR += 3;  // Default instruction size (Format 3)
        }
    }

    file.close();
    symtabFile.close();
}

void Assembler::pass2(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    std::ofstream listingFile(filename + ".l");
    if (!listingFile) {
        std::cerr << "Error: Cannot create listing file\n";
        return;
    }

    std::string line, label, opcode, operand;
    int LOC = START_ADDRESS;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> label >> opcode >> operand;

        std::string objCode = "XXXX";  // Placeholder for machine code

        if (opcode == "WORD") {
            objCode = operand; // Store WORD value
        } else if (opcode == "BYTE") {
            if (operand[0] == 'C') {
                objCode = operand.substr(2, operand.length() - 3);
            } else {
                objCode = operand.substr(2, operand.length() - 3);
            }
        } else if (opcode == "RESW" || opcode == "RESB") {
            objCode = "";
        } else {
            objCode = "F1A0";  // Placeholder opcode
        }

        listingFile << std::hex << LOC << "\t" << line << "\t" << objCode << "\n";

        if (opcode == "WORD") {
            LOC += 3;
        } else if (opcode == "RESW") {
            LOC += 3 * std::stoi(operand);
        } else if (opcode == "RESB") {
            LOC += std::stoi(operand);
        } else if (opcode == "BYTE") {
            LOC += (operand[0] == 'C') ? operand.length() - 3 : (operand.length() - 3) / 2;
        } else {
            LOC += 3;
        }
    }

    file.close();
    listingFile.close();
}
