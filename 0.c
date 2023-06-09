#include <stdarg.h>
#include <stdio.h>

/**
 * _printf: prints the document
 * @format: the format used
 * return : success
 **/
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			switch (*format, format++;)
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += printf("%%");
					break;
				default:
					count += printf("Invalid format specifier");
					break;
			}
		}
		else
		{
			count += printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
