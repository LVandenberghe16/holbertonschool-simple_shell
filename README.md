# **Simple Shell**

Welcome to **Simple Shell**, a minimalist UNIX shell implementation written in C. This project is an educational exercise to deepen understanding of systems programming, process management, and basic operating system concepts.

---

## **Table of Contents**

1. [Introduction](#introduction)
2. [Features](#features)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Supported Commands](#supported-commands)
6. [File Structure](#file-structure)
7. [Development](#development)
8. [Authors](#authors)
9. [License](#license)

---

## **Introduction**

This shell replicates the basic behavior of standard UNIX shells such as `sh` or `bash`. It supports interactive and non-interactive modes, command execution, and basic built-in functions. The project is built entirely in C, following GNU standards.

---

## **Features**

- **Command Execution**: Execute binary commands located in the system's `PATH`.  
- **Interactive Mode**: Displays a prompt (`($)`) for users to enter commands.  
- **Non-Interactive Mode**: Reads commands from standard input (e.g., via pipes or files).  
- **Environment Access**: Supports viewing the current environment variables using the `env` command.  
- **Built-in Commands**: Includes an `exit` command with optional status.  
- **Error Handling**: Provides descriptive error messages for invalid commands or inputs.  

---

## **Installation**

1. Clone the repository:
   ```bash
   git clone https://github.com/<your-repo>/simple_shell.git
   ```

2. Navigate to the project directory:
   ```bash
   cd simple_shell
   ```

3. Compile the shell using `gcc`:
   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```

---

## **Usage**

### Interactive Mode
Run the shell by typing:
```bash
./hsh
```
The shell will display a prompt:
```
($)
```
You can then enter commands like:
```bash
($) ls -l
($) pwd
($) exit
```

### Non-Interactive Mode
Provide commands via standard input:
```bash
echo "ls -l" | ./hsh
```
Or run a script:
```bash
./hsh < script.txt
```

---

## **Supported Commands**

### Built-in Commands
- `exit [status]`: Exit the shell with an optional status code.
- `env`: Display the current environment variables.

### External Commands
Any executable in the system's `PATH` can be run, such as:
- `ls`
- `pwd`
- `echo`
- `grep`

---

## **File Structure**

```
simple_shell/
├── shell.h               # Header file with function prototypes and macros
├── shell.c               # Main shell implementation
├── builtins.c            # Built-in command functions (exit, env)
├── execute.c             # Command execution logic
├── path.c                # PATH resolution logic
├── parse.c               # Command line parsing logic
├── AUTHORS               # List of project authors
├── README.md             # Project documentation
```

---

## **Development**

This project is developed using the following tools:
- **Language**: C (ISO C90 standard)
- **Compiler**: GCC
- **OS**: Linux (tested on Ubuntu and Fedora)

### Coding Style
This project follows the Betty coding style. You can install the Betty linter to check for style conformity:
```bash
git clone https://github.com/holbertonschool/Betty.git
```

---

## **Authors**

- **Ludwig Vandenberghe**
  - GitHub: [LVandenberghe16](https://github.com/LVandenberghe16)
  - Email: ludwig.vandenberghe2@gmail.com

---

## **License**

This project is licensed under the **MIT License**. Feel free to use, modify, and distribute this code for educational or personal purposes.

---
