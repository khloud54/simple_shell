#include "main.h"

/**
 * check_seprator - fun that checks if there is one operators
 * @line: pointer to string we want to check
 * @head: pointer to list of alias
 * @head_asign: pointer to list variable replacement
 * Return: one if success, -1 otherwise
*/
int check_seprator(char *line, list_t *head, list_t *head_asign)
{
	int j, i;
	oprator op[] = {{';', semcolen}, {'&', anding}, {'|', oring}, {'\0', NULL}};

	/* walk through the oprators */
	for (j = 0; op[j].ch != '\0'; j++)
	{
		/* walk through the line */
		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] == op[j].ch)
			{
				op[j].fun(line, head, head_asign);
				return (1);
			}
		}
	}
	return (-1);
}

/**
 * semcolen - fun that do the same as ; oprator do in shell
 * @line: pointer to string of the line
 * @head: pointer to the head of list of alias
 * @head_asign: pointer to list of variable replacement
*/
void semcolen(char *line, lists_t *head, list_t *head_asign)
{
	char **strings = NULL, **argv = NULL;
	int i;

	/* split each string into arguments */
	strings = split_str(line, ";");
	/* walk through each string */
	for (i = 0; strings[i] != NULL; i++)
	{
		/* split each string into arguments */
		argv = split_str_2(strings[i]);
		check_qoute(argv);/* check if there is qoute */
		execute(argv, &head, &head_asign); /* execute each string */
	}
	free(argv), free(strings);
}

/**
 * anding - fun that do the same as && oprator do in shell
 * @line: pointer to string of the line
 * @head: pointer to the head of list of alias
 * @head_asign: pointer to list of variable replacement
*/
void anding(char *line, list_t *head, list_t *head_asign)
{
	char **strings = NULL, **argv = NULL;
	int i, exec = 0;

	/* split the line into strings with && */
	strings = split_str(line, "&&");
	/* walk through each string */
	for (i = 0; strings[i] != NULL; i++)
	{
		/* if the previous execute was correct */
		if (exec == 0)
		{
			argv = split_str_2(strings[i]);
			check_qoute(argv);/* check if there is qoute */
			exec = execute(argv, &head, &head_asign);
		}
	}
	free(argv), free(strings);
}

/**
 * oring - fun that do the same as || oprator do in sh shell
 * @line: pointer to string of the line
 * @head: pointer to the head of list of alias
 * @head_asign: pointer to list of variable replacement
*/
void oring(char *line, list_t *head, list_t *head_asign)
{
	char **strings = NULL, **argv = NULL;
	int i, exec = 1;

	/* split the line into strings with && */
	strings = split_str(line, "||");
	/* walk through each string */
	for ( i = 0; strings[i] != NULL; i++)
	{
		/* if the previous execute was wromg */
		if (exec != 0 )
		{
			argv = split_str_2(strings[i]);
			check_qoute(argv);/* check if there is qoute */
			exec = execute(argv, &head, &head_asign);
		}
	}
	free(argv), free(strings);
}
