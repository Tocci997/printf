#include "main.h"
/**
 * print_int - prints integers
 * @num: number to be printwed
 * Return: value of int
 */

int print_int(int num)
{
	int num2 = 0;
	int num3 = 1;

	if (num < 0)
	{
		num = ~num + 1;
		my_putchar('-');
		num2++;

	while (num3 <= num)
		num3 *= 10;
	while (num > 0)
	{
		num3 /= 10;
		my_putchar((num / num3) + '0');
		num %= num3;
		num2++;
	}
	}
	return (num2);
}
