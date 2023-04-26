.SH NAME
simple_shell \- a simple UNIX shell

.SH SYNOPSIS
.B simple_shell
[\fIcommand\fR [\fIargs...\fR]]...

.SH DESCRIPTION
simple_shell is a lightweight implementation of a UNIX shell. It supports all basic shell functionality, including command execution, shell variables, command-line history, and batch file processing.

To start simple_shell, simply type the following command:

.nf
.B $ ./simple_shell
.fi

Once started, simple_shell will display a command prompt and wait for user input. Commands can be entered at the prompt and will be executed when the user presses the Enter key.

.SH OPTIONS
The following options are supported by simple_shell:

.TP
.B \-h, \-\-help
Display a help message and exit.

.SH EXAMPLES
The following examples demonstrate some common usage scenarios for simple_shell:

.TP
.B $ ./simple_shell
Start simple_shell and display the command prompt.

.TP
.B $ ./simple_shell -c "ls -l"
Execute the "ls -l" command and exit.

.TP
.B $ ./simple_shell script.sh
Execute the commands in the script.sh file and exit.

.SH AUTHOR
simple_shell was written by Graham & Eric.

.SH COPYRIGHT
Copyright (C) 2023 Graham & Erick. This is free software; see the source code for licensing information. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
