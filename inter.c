/*
 Assignment name  : inter
 Expected files   : inter.c
 Allowed functions: write
 --------------------------------------------------------------------------------
 en
 Write a program that takes two strings and displays, without doubles, the
 characters that appear in both strings, in the order they appear in the first
 one.

 The display will be followed by a \n.

 If the number of arguments is not 2, the program displays \n.
 ----------------------------------------------------------------------------------
 ru
 Напишите программу, которая берет две строки и отображает без двойников символы, которые появляются в обеих строках, в том порядке, в котором они появляются в первой строке.

 После этого на дисплее появится буква "\n".

 Если число аргументов не равно 2, то программа выводит \n.

 Examples:

 $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
 padinto$
 $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
 df6ewg4$
 $>./inter "nothing" "This sentence hides nothing" | cat -e
 nothig$
 $>./inter | cat -e
 $

 */

#include <unistd.h>

int is_char_present(char *str, char c, int index_max) {
    int i = 0;
    
    while (i < index_max)
    {
        if (str[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

void ft_inter(char *str1, char *str2) {
    int i = 0;
    int j;
    
    while (str1[i])
    {
        if (!is_char_present(str1, str1[i], i)) {
            j = 0;
            while (str2[j])
            {
                if (str1[i] == str2[j]) {
                    write(1, &str1[i], 1);
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        ft_inter(argv[1], argv[2]);
    }
    write(1, "\n", 1);
    return 0;
}
