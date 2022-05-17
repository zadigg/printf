#include "main.h"
/**
 * save_number - save a number
 * @args: List of arguments
 * @dest: Destiny to copy
 * @pos: Position of destiny
 * Return: The length
 */
int save_number(va_list args, char *dest, int *pos)
{
	int n, div, len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len++;
		copyto_buffer(dest, '-', pos);
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len++;
		copyto_buffer(dest, ('0' + num / div), pos);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * _base - length for an octal number
 * @num: number
 * @base: Base
 * Return: Integer
 */
unsigned int _base(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num = num / base;
	}
	return (i);
}
/**
 * rev_string - prints a string in reverse
 * @s: This is the string to evalu
 * not return
 */
void rev_string(char *s)
{
	int i = 0;
	char word;
	int si = 0;

	while (s[i] != '\0')
		i++;
	i -= 1;
	while (i > si)
	{
		word = s[i];
		s[i] = s[si];
		s[si] = word;
		si++;
		i--;
	}
}
/**
 * save_binary - number from base 10 to binary
 * @args: arguments
 * @dest: destiny to copy
 * @pos: actual position in destiny
 * Return: number
 */
int save_binary(va_list args, char *dest, int *pos)
{
	unsigned int num;
	int i, len;
	char *str;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		copyto_buffer(dest, '0', pos);
		return (1);
	}
	len = _base(num, 2);
	str = malloc(len + 1);
	if (str == NULL)
		str = "(null)";
	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num = num / 2;
	}
	str[i] = '\0';
	i = 0;
	rev_string(str);
	while (str[i] != '\0')
	{
		copyto_buffer(dest, str[i], pos);
		i++;
	}
	return (i);
}
/**
 * save_unsigned - save an unsigned number
 * @args: list or arguments
 * @dest: Destiny to copy
 * @pos: Actual position of number
 * Return: Actual position of destiny
 */
int save_unsigned(va_list args, char *dest, int *pos)
{
	unsigned int len = 0;
	int div = 1;
	unsigned int number = va_arg(args, unsigned int);

	if (number == 0)
	{
		copyto_buffer(dest, '0', pos);
		return (1);
	}
	for (; number / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len++;
		copyto_buffer(dest, ('0' + number / div), pos);
		number %= div;
		div /= 10;
	}
	return (len);
}
