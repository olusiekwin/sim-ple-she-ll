# 0x16. C - Simple Shell <br/>
`C`
`Group project`
`Syscall`

# Simple Shell Project

A simple Unix shell implementation written in C.

## Features
- Executes commands entered by the user
- Supports basic command-line syntax and shell built-in     commands
- Allows for command history and custom configuration options
- Handles signals and manages background processes

## Installation

To compile the program, use the following command:

`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Usage
To start the shell, simply run the `hsh` executable:

`$ ./hsh`

The shell prompt should be displayed, and you can enter commands as usual. Use the exit command or press Ctrl-D to exit the shell.

## Built-in Commands
The following commands are built into the shell:

- `cd`: change the working directory
- `history`: display a list of recent commands
- `help`: display information about the shell and its built-in commands
- `setenv`: set the value of an environment variable
- `unsetenv`: unset an environment variable
- `env`: display the current environment variables
- `exit`: exit the shell

## Configuration Options
The shell can be customized using the following configuration options:

- `PROMPT`: the shell prompt to display (default is "$ ")
- `HISTORY_FILE`: the name of the history file to use (default is `~/.simple_shell_history`)
- `MAX_HISTORY`: the maximum number of commands to store in the history (default is `4096`)</br>
These options can be set using the setenv command, and will be saved to a configuration file for future sessions.

## Examples
Here are some examples of how to use the shell:

```
$ ./hsh
$ ls -l
total 16
-rw-r--r-- 1 user user   27 Apr 26 14:12 hello_world.c
-rwxr-xr-x 1 user user 8096 Apr 26 14:12 hsh
$ cd ..
$ pwd
/home/user
$ help
Simple Shell - A simple Unix shell implementation

Built-in Commands:
cd [directory]           Change the current working directory
history                  Display the command history
help                     Display this help message
setenv [variable] [value] Set an environment variable
unsetenv [variable]      Unset an environment variable
env                      Display the environment variables
exit                     Exit the shell

Configuration Options:
PROMPT                   The shell prompt to display (default is "$ ")
HISTORY_FILE             The history file to use (default is ~/.simple_shell_history)
MAX_HISTORY              The maximum number of commands to store in the history (default is 4096)
$ exit

```

## Authors
- [Alphonsi](https://github.com/alphonsi)
- [Graham](https://github.com/olusiekwin)


## Licence
This project is licensed under the MIT License - see the LICENSE file for details.