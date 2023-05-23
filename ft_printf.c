/*
 Assignment name  : ft_printf
 Expected files   : ft_printf.c
 Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
 --------------------------------------------------------------------------------

 Write a function named `ft_printf` that will mimic the real printf but
 it will manage only the following conversions: s,d and x.

 Your function must be declared as follows:

 int ft_printf(const char *, ... );

 Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
 To test your program compare your results with the true printf.

 Exemples of the function output:

 call: ft_printf("%s\n", "toto");
 out: toto$

 call: ft_printf("Magic %s is %d", "number", 42);
 out: Magic number is 42%

 call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
 out: Hexadecimal for 42 is 2a$
 */

#include <unistd.h>
#include <stdarg.h>

// Function to print a string
int print_string(char *str)
{
    int i = 0;
    
    if (str == NULL)
    {
        write(1, "(null)", 6);  // Write "(null)" to standard output
        return 6;  // Return the length of the string "(null)"
    }
    
    while (str[i])
    {
        write(1, &str[i], 1);  // Write each character of the string to standard output
        i++;
    }
    
    return i;  // Return the length of the string
}

// Function to print a decimal number
int print_decimal(int num)
{
    int len = 1;
    char digit;
    
    if (num == -2147483648)
    {
        write(1, "-2147483648", 11);  // Write the minimum integer value to standard output
        return 11;  // Return the length of the string "-2147483648"
    }
    
    if (num < 0)
    {
        len++;
        write(1, "-", 1);  // Write a minus sign for negative numbers
        num = -num;  // Convert the number to its absolute value
    }
    
    if (num >= 10)
    {
        len += print_decimal(num / 10);  // Recursively print the remaining digits
    }
    
    digit = '0' + (num % 10);  // Get the last digit of the number
    write(1, &digit, 1);  // Write the digit to standard output
    
    return len;  // Return the length of the number
}

// Function to print a hexadecimal number
int print_x(unsigned int num)
{
    int len = 1;
    char digit;
    
    if (num >= 16)
    {
        len += print_x(num / 16);  // Recursively print the remaining digits
    }
    
    digit = "0123456789abcdef"[num % 16];  // Get the corresponding hexadecimal digit
    write(1, &digit, 1);  // Write the digit to standard output
    
    return len;  // Return the length of the number
}

// Main printf function implementation
int ft_printf(const char *format, ...)
{
    va_list args;  // Variable argument list
    int len = 0;  // Total length of printed characters
    
    va_start(args, format);  // Start iterating over the variable arguments
    
    while (*format)
    {
        if (*format == '%')  // Check if a format specifier is encountered
        {
            format++;  // Move to the next character after '%'
            
            if (*format == 's')  // Handle format specifier for string
            {
                char *s = va_arg(args, char *);  // Get the next argument as a string
                len = len + print_string(s);  // Print the string and update the length
                format++;  // Move to the next format specifier
            }
            if (*format == 'd')  // Handle format specifier for decimal number
            {
                int num = va_arg(args, int);  // Get the next argument as an integer
                len = len + print_decimal(num);  // Print the number and update the length
                format++;  // Move to the next format specifier
            }
            if (*format == 'x')  // Handle format specifier for hexadecimal number
            {
                unsigned int num = va_arg(args, unsigned int);
                len = len + print_x(num);
                format++;
            }
        } else {
            write(1, format, 1);
            format++;
            len++;
        }
        va_end(args);
    }
    return len;
}


