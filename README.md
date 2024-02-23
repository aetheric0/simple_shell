SHELL PROJECT MADE WITH C

Usage: ./hsh
       echo "{Command (with arguments)}" | ./hsh

Description: This executes a shell project in interactive mode when run in a
terminal. A non-interactive shell that processes a command once can also be
executed through piping.

main.c : Executes the shell in interactive or non-interactive mode based on the
usage.

_prompt(): Reads and formats line from STDIN by terminating newline char '\n'
with the null byte '\0'.

_tokens(): Tokenize each string passed by user before parsing to execve to
execute. It ensures the command as well as its arguments are stored in an
array which the system call execve can access and execute according to the
user input.

_shell_loop(): Loops the shell process to ensure the shell stays in interactive
mode when executed.