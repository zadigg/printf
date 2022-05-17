#include "main.h"
/**
 * looktype - search a type in va_list and save into a buffer
 * @s: string compare to determine the type
 * Return: Call a function
 */
int (*looktype(char s))(va_list args, char *dest, int *pos)
{
	int i = 0;
	vargs calls[] = {
		{'s', save_string},
		{'c', save_char},
		{'d', save_number},
		{'i', save_number},
		{'u', save_unsigned},
		{'o', save_octal},
		{'x', save_lwhexa},
		{'X', save_uphexa},
		{'R', save_rot13},
		{'r', save_reverse},
		{'b', save_binary},
		{'%', save_percent},
		{'\0', NULL}
	};
	while (calls[i].typef != '\0')
	{
		if (s == calls[i].typef)
			return (calls[i].f);
		i++;
	}
	return (NULL);
}
