#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
/**
 * struct vaargs - struct to canalize buffer
 * @typef: Type of format
 * @f: pointer to function
 */
typedef struct vaargs
{
	char typef;
	int (*f)();
} vargs;
int _printf(const char *format, ...);
int _putchar(char c);
void copyto_buffer(char *dest, char letter, int *pos);
int (*looktype(char s))(va_list args, char *dest, int *pos);
int save_string(va_list args, char *dest, int *pos);
int save_char(va_list args, char *dest, int *pos);
void rev_string(char *s);
int save_number(va_list args, char *dest, int *pos);
int save_percent(va_list args, char *dest, int *pos);
int save_binary(va_list args, char *dest, int *pos);
int save_unsigned(va_list args, char *dest, int *pos);
int save_octal(va_list args, char *dest, int *pos);
int save_lwhexa(va_list args, char *dest, int *pos);
int save_uphexa(va_list args, char *dest, int *pos);
int save_rot13(va_list args, char *dest, int *pos);
int save_reverse(va_list args, char *dest, int *pos);
unsigned int _base(unsigned int num, int base);
#endif
