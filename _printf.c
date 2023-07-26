#include "main.h"
/**
 * _printf - function to work with printf
 * @format: format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char chare, *str;
	va_list data_type;

	if (format == NULL)
		return (-1);
	va_start(data_type, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			i++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				i++;
			} else if (*format == 'c')
			{
				chare = va_arg(data_type, int);
				write(1, &chare, 1);
				i++;
			} else if (*format == 's')
			{
				str = va_arg(data_type, char *);
				write(1, str, strlen(str));
				i++;
			}
		}
		format++;
	}
	va_end(data_type);
	return (i);
}
