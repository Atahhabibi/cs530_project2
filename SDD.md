# **Software Design Document (SDD)**
## **CS530 - Project #2: Limited XE Assembler**

### **Team Information**
| Name | CSSC ID | Red ID | Role |
|------|--------|--------|------|
| Atah Habibi | csscXXXX | XXXXXXXX | Lead Developer, Debugging, Documentation |
| Chante Langues | csscYYYY | YYYYYYYY | System Design, Testing, Code Review |

---

## **1. Overview & Goals**
### **Overview**
This project implements a **two-pass assembler** for the **SIC/XE machine architecture**. The assembler processes SIC/XE assembly source files (`.sic`) and generates:
- **Listing file (`.l`)**
- **Symbol table file (`.st`)**

### **Goals**
- Implement **Pass 1** to build the **SYMTAB (Symbol Table)**.
- Implement **Pass 2** to generate **Listing files**.
- Ensure **modular, well-documented code**.
- Develop efficient **testing strategies** to validate assembler functionality.

---

## **2. System Design**
### **Architecture**
- **Pass 1**: Reads `.sic` file, builds `SYMTAB`, calculates addresses.
- **Pass 2**: Generates `.l` file and `.st` file.

### **Data Structures**
- **SYMTAB (Symbol Table)**: Hash table mapping labels to addresses.
- **OPTAB (Opcode Table)**: Lookup table for SIC/XE instructions.

### **Development Roles**
- **Atah Habibi**
  - Lead Developer: Responsible for implementing the **core assembler logic**.
  - Debugging: Ensure error handling and resolve implementation bugs.
  - Documentation: Write the README, comment the code, and assist in report writing.
- **Chante Langues**
  - System Design: Develop pseudocode, plan the assembler's functionality, and structure.
  - Testing: Develop and run test cases, verify correctness, and handle corner cases.
  - Code Review: Ensure maintainability, readability, and best practices.

---

## **3. Development Milestones**
| Phase | Date | Task |
|-------|------|------|
| Phase 1 | Week 1-2 | Research & define assembler structure, assign roles |
| Phase 2 | Week 3-6 | Implement Pass 1 (SYMTAB generation) |
| Phase 3 | Week 7-8 | Implement Pass 2 (Listing file generation) |
| Phase 4 | Week 9-10 | Debugging, Testing, Optimization |
| Phase 5 | Week 11 | Documentation & Final Submission |

---

## **4. Testing Strategy**
- **Unit Testing**: Validate individual functions (file handling, SYMTAB processing, opcode handling).
- **Integration Testing**: Ensure `pass1()` and `pass2()` work together correctly.
- **System Testing**: Run the assembler against provided and custom `.sic` files.
- **Edge Case Testing**: Test missing labels, undefined opcodes, and invalid instructions.

---

## **5. Submission Details**
- **Final Deliverables:**
  - `essy` executable.
  - Source code (`.cpp` and `.h` files).
  - `Makefile`.
  - Test files (`.sic` input files, `.l` and `.st` outputs).
  - `README.md`.
  - `SDD.pdf` (converted from this document for final submission).
