#include "main.h"
int my_string(char *str)
{
	int index = 0, len = 0;
	if(str)
	{
		while(str[index] != '\0')
		{
			my_putchar(str[index]);
			len += 1;
				index++;
		}
	}
	return (len);
}
