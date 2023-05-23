/*
 Assignment name  : union
 Expected files   : union.c
 Allowed functions: write
 --------------------------------------------------------------------------------
 en
 Write a program that takes two strings and displays, without doubles, the
 characters that appear in either one of the strings.

 The display will be in the order characters appear in the command line, and
 will be followed by a \n.

 If the number of arguments is not 2, the program displays \n.

 $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
 zpadintoqefwjy$
 $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
 df6vewg4thras$
 $>./union "rien" "cette phrase ne cache rien" | cat -e
 rienct phas$
 $>./union | cat -e
 $
 $>
 $>./union "rien" | cat -e
 $
 $>

 */

#include <unistd.h>

/*
The is_char_present function checks whether a given character is already present
in the string up to a given maximum index. This function is used to ensure that
each character is only printed once.
*/
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

/*
The ft_union function iterates through the first string and prints each character 
that is not already present in the string up to that point.
Then it iterates through the second string and prints each character that is
not present in either the first or the second string up to that point.
Finally, it prints a newline character.*/

void ft_union(char *str1, char *str2) {
    int i = 0;
    int j = 0;

    while (str1[i])
    {
        if (!is_char_present(str1, str1[i], i)) {
            write(1, &str1[i], 1);
        }
        i++;
    }

    while (str2[j])
    {
        if (!is_char_present(str1, str2[j], i) && !is_char_present(str2, str2[j], j)) {
            write(1, &str2[j], 1);
        }
        j++;
    }
}

int main(int argc, char **argv) {
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    
    write(1, "\n", 1);
    return 0;
}
