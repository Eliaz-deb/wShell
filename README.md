# wSH - Wei Shell 🐧

## 📖 Description
A minimalist shell (command interpreter) written in pure C,
inspired by Bash. It lets you run Linux system commands
(`ls`, `pwd`, `cat`, `ping`, etc.) directly from your own program.

## ✨ Features
- Interactive command reading (REPL loop)
- Argument parsing (e.g., `ls -la` handles options properly)
- Execution via `fork()` + `execvp()` system calls
- Error handling (command not found → clean message, no crash)
- Buffer cleanup (stripping the trailing `\n` with `strcspn`)

## 🧠 What I Learned
- The fundamental difference between `fork()` (creating a process)
  and `exec()` (replacing the process with another program)
- String tokenizing with `strtok()`
- Why a trailing `NULL` is essential to mark the end of an argument array

## 🛠️ Compilation
```bash
gcc -Wall -Wextra -o wsh mini_shell.c
./wsh
