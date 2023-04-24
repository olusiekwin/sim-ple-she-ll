#include "shelly.h"

/**
 * _info - initializes cmd_info_t struct
 * @data: struct address
 */
void _info(cmd_info_t *data)
{
	data->arg_str = NULL;
	data->arg_list = NULL;
	data->path_str = NULL;
	data->arg_count = 0;
}

/**
 * _setinfo - initializes cmd_info_t struct
 * @data: struct address
 * @av: argument vector
 */
void _setinfo(cmd_info_t *data, char **av)
{
	int i = 0;

	data->fname = av[0];
	if (data->arg_str)
	{
		data->arg_list = strtow(data->arg_str, " \t");
		if (!data->arg_list)
		{

			data->arg_list = malloc(sizeof(char *) * 2);
			if (data->arg_list)
			{
				data->arg_list[0] = _strdup(data->arg_str);
				data->arg_list[1] = NULL;
			}
		}
		for (i = 0; data->arg_list && data->arg_list[i]; i++)
			;
		data->arg_count = i;

		replace_alias(data);
		replace_vars(data);
	}
}

/**
 * _freeinfo - frees cmd_info_t struct fields
 * @data: struct address
 * @all: true if freeing all fields
 */
void _freeinfo(cmd_info_t *data, int all)
{
	ffree(data->arg_list);
	data->arg_list = NULL;
	data->path_str = NULL;
	if (all)
	{
		if (!data->cmd_buf_ptr)
			free(data->arg_str);
		if (data->env_list)
			free_list(&(data->env_list));
		if (data->history_list)
			free_list(&(data->history_list));
		if (data->alias_list)
			free_list(&(data->alias_list));
		ffree(data->env_array);
			data->env_array = NULL;
		bfree((void **)data->cmd_buf_ptr);
		if (data->read_fd > 2)
			close(data->read_fd);
		_putchar(BUF_FLUSH);

	}
}
