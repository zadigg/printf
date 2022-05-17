#include "main.h"
/**
 * save_octal - save a number converted to octal into buffer to print
 * @args: list of arguments
 * @dest: Destiny to copy
 * @pos: actual position of buffer
 * Return: Length of number
 */
int save_octal(va_list args, char *dest, int *pos)
{
	unsigned int num;
	int len;
	char *octal;
	unsigned int i = 0;

	num = va_arg(args, unsigned int);

	if (num == 0)
	{
		copyto_buffer(dest, '0', pos);
		return (1);
	}
	len = _base(num, 8);

	octal = malloc(sizeof(char) * len + 1);
	if (octal == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal[len] = (num % 8) + '0';
		num = num / 8;

	}
	octal[len] = '\0';
	rev_string(octal);
	while (octal[i] != '\0')
	{
		copyto_buffer(dest, octal[i], pos);
		i++;
	}
	return (i);
}
/**
 * save_lwhexa - save a number converted to octal into buffer to print
 * @args: list of arguments
 * @dest: Destiny to copy
 * @pos: actual position of buffer
 * Return: Length of number
 */
int save_lwhexa(va_list args, char *dest, int *pos)
{
	char lower[] = "0123456789abcdef";
	int len = 0, i = 0;
	char *lwhexa;
	unsigned int number = va_arg(args, unsigned int);

	if (number == 0)
	{
		copyto_buffer(dest, '0', pos);
		return (1);
	}
	len = _base(number, 16);

	lwhexa = malloc(sizeof(char) * len + 1);
	lwhexa[len + 1] = '\0';
	if (lwhexa == NULL)
		return (-1);
	do {
		lwhexa[--len] = lower[number % 16];
		number /= 16;
	} while (number != 0);
	while (lwhexa[i] != '\0')
	{
		copyto_buffer(dest, lwhexa[i], pos);
		i++;
	}
	return (i);
}
/**
 * save_uphexa - save a number converted to octal into buffer to print
 * @args: list of arguments
 * @dest: Destiny to copy
 * @pos: actual position of buffer
 * Return: Length of number
 */
int save_uphexa(va_list args, char *dest, int *pos)
{
	char lower[] = "0123456789ABCDEF";
	int len = 0, i = 0;
	char *lwhexa;
	unsigned int number = va_arg(args, unsigned int);


	if (number == 0)
	{
		copyto_buffer(dest, '0', pos);
		return (1);
	}
	len = _base(number, 16);

	lwhexa = malloc(sizeof(char) * len + 1);
	lwhexa[len + 1] = '\0';
	if (lwhexa == NULL)
		return (-1);
	do {
		lwhexa[--len] = lower[number % 16];
		number /= 16;
	} while (number != 0);
	while (lwhexa[i] != '\0')
	{
		copyto_buffer(dest, lwhexa[i], pos);
		i++;
	}
	return (i);
}
