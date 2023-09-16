#include"main.h"

/**_printf - entry point
 * *format: pointer
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;
	char char_value;
	char *string_value;
	int length;

	if (format == NULL)
	{
		return(-1);
	}
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char_value = va_arg(args, int);
				write(1, &char_value, 1);
				count++;
			}
			if (format[i] == 's')
			{
				string_value = va_arg(args, char*);
				for (length = 0; string_value[length] != '\0'; length++)
					;
				write(1, string_value, length);
				count++;
			}
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
		}
	}
		va_end(args);
		return(count);
	
}
int main()
{
	char c = 'A';
	char* s = "Hello, world!";
	_printf("Character: %c%s%%\n", c,s);
	_printf("String: %s\n", s);
	_printf("Percent sign: %%\n");

	return (0);
}


