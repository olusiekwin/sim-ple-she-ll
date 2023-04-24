#include "shelly.h"

/**
* _envm - outputs current enviroment.
* @data: Potential arguments for maintanance.
*
* Return: 0.
*/

int _envm(cmd_info_t *data)
{
print_list_str(data->env_list);
return (0);
}

/**
* _getenvm - get value of var in the enviroment.
* @data: Potential arguments for maintanance
* @jina: env var name
*
* Return: Value.
*/

char *_getenvm(cmd_info_t *data, const char *jina)
{
list_t *node = data->env_list;
char *p;

while (node)
{
p = starts_with(node->str, jina);
if (p && *p)
return (p);
node = node->next;
}
return (NULL);
}

/**
* _setenvm - initializes new while also modifies existing.
* @data: Potential arguments for maintanance
*
* Return: 0.
*/
int _setenvm(cmd_info_t *data)
{
if (data->arg_count != 3)
{
_eputs("Number of arguments incorrect\n");
return (1);
}
if (_setenv(data, data->arg_list[1], data->arg_list[2]))
return (0);
return (1);
}

/**
* _unsetenvm - Remove an environment variable
* @data: Potential arguments for maintanance
*
*  Return: 0
*/

int _unsetenvm(cmd_info_t *data)
{
int q;

if (data->arg_count == 1)
{
_eputs("Less to many Arguments.\n");
return (1);
}
for (q = 1; q <= data->arg_count; q++)
_unsetenv(data, data->arg_list[q]);
return (0);
}

/**
* populate_envm_list - populates the linked list env
* @data: Potential arguments for maintanance
*
* Return: 0.
*/
int populate_envm_list(cmd_info_t *data)
{
list_t *node = NULL;
size_t q;

for (q = 0; environ[q]; q++)
add_node_end(&node, environ[q], 0);

data->env_list = node;
return (0);
}
