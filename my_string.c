#include "main.h"
/**
 * my_string - function to print a string
 * @str: pointer to the string
 * Return: the value of string
 */
int my_string(char *str)
{
	int index = 0, r_value = 0;

	if (str)
	{
		while (str[index] != '\0')
		{
			my_putchar(str[index]);
			r_value += 1;
				index++;
		}
	}
	return (r_value);
}
