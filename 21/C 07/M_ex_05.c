#include <unistd.h>

void ft_print_words_tables(char **tab);
char **ft_split_whitespaces(char *str);

int main()
{
    char str[] = "Happy Easter, evel devil";
    char **result = ft_split_whitespaces(str);

    ft_print_words_tables(result);

    return 0;
}

char **ft_split_whitespaces(char *str)
{
    int count = 0, i, j = 0, k = 0;

    for (i = 0; str[i]; i++)
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            count++;

    char **arr = malloc((count + 1) * sizeof(char *));

    for (i = 0; str[i]; i++, k++)
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            arr[j++] = malloc(k * sizeof(char) + 1);
            k = 0;
            continue;
        }
    arr[j] = malloc(k * sizeof(char));

    for (i = 0, j = 0, k = 0; str[i]; i++)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            arr[j][k + 1] = '\000';
            j++;
            k = 0;
            continue;
        }
        arr[j][k++] = str[i];
    }
    arr[j][k] = '\000';

    return arr;
}

void ft_print_words_tables(char **tab)
{
    int count = 0;
    for (int i = 0; tab[i]; i++)
    {
        for (int j = 0; tab[i][j]; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
}