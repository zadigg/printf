#include "main.h"
/**
 * save_rot13 - save an encrypted rot13 string into buffer
 * @args: list of args
 * @dest: buffer
 * @pos: last position in buffer
 * Return: Length of string
 */
int save_rot13(va_list args, char *dest, int *pos)
{
	int i;
	int x;
	int length = 0;
	char *str = va_arg(args, char *);
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 51; x++)
		{
			if (str[i] == s[x])
			{
				copyto_buffer(dest, u[x], pos);
				length++;
				break;
			}
		}
		if (!s[x])
		{
			copyto_buffer(dest, str[i], pos);
			length++;
		}
	}
	return (length);
}
/**
 * save_reverse - save an encrypted rot13 string into buffer
 * @args: list of args
 * @dest: buffer
 * @pos: last position in buffer
 * Return: Length of string
 */
int save_reverse(va_list args, char *dest, int *pos)
{
	int i = 0, j;
	char *str, *tmp, sw1, sw2;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";

	while (str[i] != '\0')
		i++;

	tmp = malloc(i + 1);

	if (!tmp)
		return (-1);

	for (j = 0; j < i; j++)
	{
		sw1 = str[j];
		sw2 = str[(i - 1) - j];
		tmp[j] = sw2;
		tmp[(i - 1) - j] = sw1;
		copyto_buffer(dest, tmp[j], pos);
	}

	free(tmp);
	return (i);
}
