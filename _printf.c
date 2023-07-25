#include "main.h"
/**
 * _printf - function to work with printf
 * @format: format specifier
 * Return: value of_printf
 */
int _printf(const char *format, ...)
{
	unsigned int b = 0, r_value = 0;

	va_list args;

	va_start(args, format);

	for (; format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			my_putchar(format[b]);
			r_value += 1;
		}
		if (format[b + 1] == 'c')
		{
			my_putchar(va_arg(args, int));
			b++;
		}
		if (format[b + 1] == 's')
		{
			int r_string = my_string(va_arg(args, char*));

			b++;
			r_value += r_string - 1;
		}
		if (format[b + 1] == '%')
		{
			my_putchar('%');
			b++;
			r_value += 1;
		}
		if ((format[b + 1] == 'd') || (format[b + 1] == 'i'))
		{
			int n = print_int(va_arg(args, int));
			
			r_value += print_int(n);
			if(!n)
			{
				r_value++;
				my_putchar('0');
			}
			else
				r_value += print_int(n);
		}
	}
	return (r_value);
}
