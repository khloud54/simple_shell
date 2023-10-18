#include "shell.h"

/**
<<<<<<< HEAD
 * _eputs - prints an input string
=======
 * _eputs - prints an input string 
>>>>>>> d180a9d4d290a97618611e7de925f97455fd32de
 * @str: the string to be printed
 * Return: Nothing
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character c to stderr
<<<<<<< HEAD
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
=======
 * @c: The character tp print
 * Return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
>>>>>>> d180a9d4d290a97618611e7de925f97455fd32de
*/
int _eputchar(char c)
{
	static int i;
<<<<<<< HEAD
	static char buf[WRIITE_BUF_SIZE];

	if (c  == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, 1);
=======
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
>>>>>>> d180a9d4d290a97618611e7de925f97455fd32de
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
<<<<<<< HEAD
 * @c: The character to print
=======
 * @c: the character to print
>>>>>>> d180a9d4d290a97618611e7de925f97455fd32de
 * @fd: The filedescriptor to write to
 * Return: on success 1.
 * on error, -1 is returned, and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
*/
int _putsfd(char *str, int fd)
{
<<<<<<< HEAD
	int i = 0;

	if (!str)
		return (0);
=======
	int i = 0

		if (!str)
			return(0);
>>>>>>> d180a9d4d290a97618611e7de925f97455fd32de
	while (*str)
	{
		i+= _putfd(*str++, fd);
	}
	return (i);
}
