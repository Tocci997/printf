#include "main.h"
/**
 * _printf - function to work with printf
 * @format: format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int b = 0, len = 0;

	va_list args;

	va_start(args, format);

	for (; format[b] != '\0'; b++)
	{
		if (format[b] != '%')
		{
			my_putchar(format[b]);
			len += 1;
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
			len += r_string - 1;
		}
		if (format[b + 1] == '%')
		{
			my_putchar('%');
			b++;
			len += 1;
		}
		if ((format[b + 1] == 'd') || (format[b + 1] == 'i'))
		{
			int n = print_int(va_arg(args, int));

			len += print_int(n);
			if (!n)
			{
				len++;
				my_putchar('0');
			} else
				r_value += print_int(n);
		}
		len += 1;
	}
	return (len);
}
