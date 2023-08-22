#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list list;
    char buffer[BUFF_SIZE];
    int buff_ind = 0;

    if (format == NULL)
        return (-1);

    va_start(list, format);

    while (*format)
    {
        if (*format != '%')
        {
            buffer[buff_ind++] = *format;
            if (buff_ind == BUFF_SIZE - 1)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            printed_chars += handle_format(&format, &list, buffer, &buff_ind);
        }
        format++;
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        write(1, buffer, *buff_ind);
        *buff_ind = 0;
    }
}

int handle_format(const char **format, va_list *list, char buffer[], int *buff_ind)
{
    // Implement your logic to handle format specifiers and put the output into 'buffer'.
    // Modify 'buff_ind' accordingly.
    // Return the number of characters printed.

    // Example (for simplicity, you need to handle all format specifiers):
    if (**format == 'd')
    {
        int num = va_arg(*list, int);
        // Convert 'num' to a string and copy it to 'buffer'.
        // Update 'buff_ind' and return the number of characters printed.
    }
    else if (**format == 's')
    {
        char *str = va_arg(*list, char *);
        // Copy 'str' to 'buffer'.
        // Update 'buff_ind' and return the number of characters printed.
    }
    // Handle other format specifiers as needed.
    // ...

    // If the format specifier is not supported, return 0.
    return 0;
}

