/*
Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.

*/

#include "get_next_line.h"

char *get_next_line(fd)
{
    char *line;  // Variable to store the resulting line
    char save[999999];  // Buffer to hold the read characters
    char buff[1];  // Buffer to read one character at a time
    int i;  // Counter variable
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);  // Invalid file descriptor or buffer size, return NULL
    
    i = 0;
    save[0] = 0;  // Initialize the save buffer
    
    while (read(fd, &buff, 1) == 1)  // Read one character at a time from the file descriptor
    {
        save[i] = buff[0];  // Store the character in the save buffer
        save[i + 1] = 0;  // Null-terminate the save buffer
        if (save[i] == '\n')  // Break if a newline character is encountered
            break;
        i++;
    }
    
    if (!save[0])
        return (NULL);  // If save buffer is empty, return NULL
    
    line = malloc(i + 1);  // Allocate memory for the resulting line
    
    if (!line)
        return (NULL);  // Memory allocation failed, return NULL
    
    i = 0;
    while (save[i])  // Copy characters from save buffer to the line
    {
        line[i] = save[i];
        i++;
    }
    line[i] = 0;  // Null-terminate the line
    
    return (line);  // Return the resulting line
}
