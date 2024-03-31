# Shell Project (hsh) - A Simple Unix Shell in C

![image](https://github.com/aetheric0/simple_shell/assets/125897342/794b43e6-90e9-40c2-a202-babc7391f2c0)


## Overview
This project implements a basic Unix shell in C. It allows users to execute
commands interactively or via piping. The shell provides essential features like
command parsing, tokenization, and execution.

## Usage
- To run the shell interactively:
  ```
  ./hsh
  ```
- To execute a single command via piping:
  ```
  echo "{Command (with arguments)}" | ./hsh
  ```

## Components
1. **main.c**: Responsible for executing the shell in interactive or
   	       non-interactive mode based on usage.
2. **prompt.c**: Reads and formats input lines from STDIN, terminating newline
   		 characters with null bytes.
3. **tokens.c**: Tokenizes user input, ensuring commands and arguments are
   		 stored in an array for execution.
4. **shell_loop.c**: Maintains the shell's interactive mode until it receives a
   		     SIGTERM signal.
5. **handle_path.c**: Handles shell commands without full paths (e.g., `ls`, `pwd`).
6. **main.h**: Contains guarded header files with function definitions and
   	       includes.

## Repository Structure
- The repository includes a project directory called "simple_shell_test_suite,"
which was used during development for test cases. If it's no longer needed, feel
free to remove it.

## Getting Started
1. Clone this repository.
2. Compile the shell program:
   ```
   gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
   ```
3. Run the shell interactively or via piping as described above.

4. If you modify the program, or want to use it for debugging purposes, it is
   advisable to use `Valgrind` to check for memory leaks with this commad:
  ```
  valgrind --leak-check=full --show-leak-kinds=all ./hsh
  ```

## Contributing
Contributions are welcome! If you find any issues or want to improve the shell,
feel free to submit a pull request.

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for
details.

---
