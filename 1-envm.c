#include "shelly.h"

/**
* get_envm - returns the string array copy of our environ
* @data: Structure containing potential arguments. Used to maintain
*          constant function prototype.
* Return:  0
*/

char **get_envm(cmd_info_t *data)
{
if (!data->env_array || data->env_changed)
{
data->env_array = list_to_strings(data->env_array);
data->env_changed = 0;
}
return (data->env_array);

}

/**
 * _setenv - Initializes  new environment variable,
 *             or modifise existing one
 * @data: Structure contains potential arguments. Used in maintaining
 *        constant function prototype.
 * @var: the string env var property
 * @val: the string env var value
 * 
 *  Return:  0
 */

int _setenv(cmd_info_t *data, char *var, char *value)