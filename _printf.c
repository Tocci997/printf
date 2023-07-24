#include "main.h"
/**
 * _printf - function to work with printf
 * @format: format specifier
 * Return: value of_printf
 */
int _printf(const char *format, ...)
{
	unsigned h = 0, r_value = 0;

	va_list args;

	va_start(args, format);
	for(; format[h] != '\0'; h++)
	{
		if (format[h] != '%')
		{
			my_putchar(format[h]);
			r_value += 1;
		}
		else if (format[h + 1] == 'c')
		{
			my_putchar(va_arg(args, int));
			h++;
		}
		else if (format[h + 1] == 's')
		{
			int r_string = my_string(va_arg(args, char*));
			h++;
			r_value += r_string - 1;
		}
		else if (format[h + 1] == '%')
		{
			my_putchar('%');
			h++;
			r_value += 1;
		}
	}
	return (r_value);
}
