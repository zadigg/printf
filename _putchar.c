#include <unistd.h>
/**
 * _putchar - prints a character
 * @c: character to print
 * Return: An output for a char
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
