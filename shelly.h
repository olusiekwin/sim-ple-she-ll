#ifndef SHELLY_H
#define SHELLY_H

#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* for buffer sizes */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_AND 2
#define CMD_CHAIN 3
#define CMD_NORM 0
#define CMD_OR 1

/* input function selection */
#define USE_GETLINE 0
#define USE_STRTOK 0

/* for history */
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/* for environment variables */
extern char **environ;

/**
* struct liststr - singly linked list
* @id: the ID field
* @str: a string
* @next: points to the next node
*/
typedef struct liststr
{
int id;
char *str;
struct liststr *next;
} list_t;

/**
* struct cmd_info_t - contains information to be passed into a function,
*                     allowing uniform prototype for function pointer struct
* @arg_str: a string generated from getline containing arguments
* @arg_list: an array of strings generated from arg_str
* @path_str: a string path for the current command
* @arg_count: the argument count
* @line_cnt: the error count
* @err_code: the error code for exit()s
* @linecount_flag: if on count this line of input
* @fname: the program filename
* @env_list: linked list local copy of environ
* @history_list: linked list of command history
* @alias_list: linked list of command aliases
* @env_array: custom modified copy of environ from env_list
* @env_changed: on if env_array was changed
* @exec_status: the return status of the last exec'd command
* @cmd_buf_ptr: pointer to command chain buffer for memory management
* @cmd_buf_type: command buffer type: ||, &&, ;
* @read_fd: the fd from which to read line input
* @hist_count: the history line number count
*/
typedef struct cmd_info_t
{
char *arg_str;
char **arg_list;
char *path_str;
int arg_count;
unsigned int line_cnt;
int err_code;
int linecount_flag;
char *fname;
list_t *env_list;
list_t *history_list;
list_t *alias_list;
char **env_array;
int env_changed;
int exec_status;
char **cmd_buf_ptr;
int cmd_buf_type;
int read_fd;
int hist_count;
} cmd_info_t;

#define CMD_INFO_INIT {NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, \
NULL, 0, 0, NULL, 0, 0, 0}



/**
* struct builtin_func - contains a builtin command string and its function
* @command_str: the command string
* @func_ptr: the function pointer for the command
*/
typedef struct builtin_func
{
char *command_str;
int (*func_ptr)(cmd_info_t *);
} builtin_func_t;

/* hsh.c */
int hsh(cmd_info_t *, char **);
int find_builtin(cmd_info_t *);
void find_cmd(cmd_info_t *);
void fork_cmd(cmd_info_t *);

/* path.c */
int is_cmd(cmd_info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(cmd_info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* err_string_functions.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* string_functions.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* string_functions2.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* string_functions3.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* string_functions4.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* memory_functions */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory_functions2.c */
int bfree(void **);

/* more_functions.c */
int interactive(cmd_info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* more_functions2.c */
int _erratoi(char *);
void print_error(cmd_info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* builtin_emulators.c */
int _myexit(cmd_info_t *);
int _mycd(cmd_info_t *);
int _myhelp(cmd_info_t *);

/* builtin_emulators2.c */
int _myhistory(cmd_info_t *);
int _myalias(cmd_info_t *);

/* getline.c module */
ssize_t get_input(cmd_info_t *);
int _getline(cmd_info_t *, char **, size_t *);
void sigintHandler(int);

/* info.c module */
void _info(cmd_info_t *);
void _setinfo(cmd_info_t *, char **);
void _freeinfo(cmd_info_t *, int);

/* envm.c module */
char *_getenvm(cmd_info_t *, const char *);
int _envm(cmd_info_t *);
int _setenvm(cmd_info_t *);
int _unsetenvm(cmd_info_t *);
int populate_envm_list(cmd_info_t *);

/* 1-envm.c module */
char **get_envm(cmd_info_t *);
int _unsetenv(cmd_info_t *, char *);
int _setenv(cmd_info_t *, char *, char *);

/* file_io_functions.c */
char *get_history_file(cmd_info_t *info);
int write_history(cmd_info_t *info);
int read_history(cmd_info_t *info);
int build_history_list(cmd_info_t *info, char *buf, int linecount);
int renumber_history(cmd_info_t *info);

/* liststr.c module */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* liststr2.c module */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* chain.c */
int is_chain(cmd_info_t *, char *, size_t *);
void check_chain(cmd_info_t *, char *, size_t *, size_t, size_t);
int replace_alias(cmd_info_t *);
int replace_vars(cmd_info_t *);
int replace_string(char **, char *);

#endif /* SHELLY_H */
