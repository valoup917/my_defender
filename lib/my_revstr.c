/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** .
*/

char *my_revstr(char *str)
{
    int n = 0;
    int d = 0;
    int len;
    char b;

    for (; str[n] != '\0'; n++);
    len = n - 1;
    for (int i = 0; i <= len / 2; i++) {
        b = str[n-1];
        str[n-1] = str[d];
        str[d] = b;
        d++;
        n--;
    }
    return (str);
}
