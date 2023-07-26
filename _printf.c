#include "main.h"
/**
 * _printf - function to work with printf
 * @format: format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;

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
			if (*format == 'c')
			{
				char chare = va_arg(data_type, int);

				write(1, &chare, 1);
				i++;
			}
			if (*format == 's')
			{
				char *str = va_arg(data_type, char *);

				int len = 0;

				while (str[len] != '\0')
					len++;
				write(1, str, len);
				i += len;
			}
		}
		format++;
	}
	va_end(data_type);
	return (i);
}
