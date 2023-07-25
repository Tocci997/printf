#include "main.h"
#include <stdio.h>
/**
 * my_putchar - function for to print a single character
 * @a: character variable
 * Return: 0 success
 */

int my_putchar(char a)
{
	return (write(1, &a, 1));
}
