# **Limited XE Assembler - CS530 Project #2**

## **Project Overview**
This project is a **two-pass assembler** for the XE variant of the SIC/XE machine architecture. It processes **SIC/XE assembler source files (`.sic`)** and generates:
- **Listing files (`.l`)**
- **Symbol table files (`.st`)**

🚀 **Key Features:**
- Implements **all XE features and assembler directives** (up to section 2.3.4).
- **Two-pass assembler logic**:
  - **Pass 1:** Builds the **SYMTAB** and calculates addresses.
  - **Pass 2:** Generates **listing files** and writes the **symbol table** to disk.
- Runs from the **command line** with multiple source files as arguments.
- **Does not generate object code**.

---

## **Project Requirements**
### ✅ **General Requirements**
- Written in **C/C++** (using `gcc/g++`).
- Must use **Makefile** to compile.
- Must include a **README.md** file with usage instructions.
- **Code should be well-commented** for readability.
- Works on **Edoras server** (`Linux` environment).

### 📚 **File Requirements**
| **File Type** | **Description** |
|--------------|----------------|
| `.sic`  | SIC/XE assembler source file |
| `.l`    | SIC/XE listing file (output) |
| `.st`   | SIC/XE symbol table file (output) |
| `Makefile` | Build automation |
| `README.md` | Project documentation |
| `test/` | Test files for validation |

---

## **🔹 Compilation & Running the Program**
### **🔹 Compilation**
To compile the assembler, navigate to the project directory and run:
```sh
make
```
This will generate an executable file named `essy`.

### **🔹 Running the Assembler**
To run the assembler with SIC/XE source files:
```sh
./essy test/example.sic
```
If multiple `.sic` files need to be processed, pass them as arguments:
```sh
./essy file1.sic file2.sic file3.sic
```

### **🔹 Cleaning Compiled Files**
To remove compiled binaries and object files:
```sh
make clean
```

---

## **Testing the Assembler**
1. **Run with a sample SIC/XE file**:
   ```sh
   ./essy test/example.sic
   ```
2. **Check output files**:
   ```sh
   cat test/example.l   # View the listing file
   cat test/example.st  # View the symbol table
   ```
3. **Debugging with `gdb`** (optional):
   ```sh
   gdb ./essy
   ```

---

## **Development Environment**
- **OS**: Linux (Edoras)
- **Compiler**: GCC (`g++`)
- **IDE**: VS Code, Vim
- **Version Control**: GitHub

# cs530_project2
