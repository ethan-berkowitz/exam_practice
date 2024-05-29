#include <stdlib.h>
#include <stdio.h>

int count_words(char *str)
{
    int count = 0;

    while (*str)
    {
        while (*str == 9 || *str == 10 || *str == 32)
            str++;
        if (*str)
            count++;
        while (*str && *str != 9 && *str != 10 && *str != 32)
            str++;
    }
    return (count);
}

int get_len(char *str)
{
    int len;

    len = 0;
    while (*str && *str != 9 && *str != 10 && *str != 32)
    {
        len++;
        str++;
    }
    return (len);
}

char **free_null(char **strstr, int i)
{
    while (i >= 0)
        free(strstr[i]);
    free(strstr);
    return (NULL);
}

char    **ft_split(char *str)
{
    char    **strstr;
    int words;
    int i;
    int j;
    int word_length;

    if (!str)
        return (NULL);
    words = 0;
    words = count_words(str);
    //printf("words: %d\n", words);
    strstr = (char **)malloc(sizeof(char *) * (words + 1)); //does the terminating 0 get a size of char* allocated for it?
    if (!strstr)
        return (NULL);
    i = 0;
    while (i < words)
    {
        while (*str == 9 || *str == 10 || *str == 32)
            str++;

        word_length = get_len(str);
        //printf("%d\n", word_length);
        strstr[i] = (char *)malloc(sizeof(char) * (word_length + 1));
        if (!strstr[i])
            return (free_null(strstr, i));
        j = 0;
        while (*str && *str != 9 && *str != 10 && *str != 32)
        {
            strstr[i][j] = *str;
            str++;
            j++;
        }
        strstr[i][j] = '\0';
        //printf("new_string: %s\n", strstr[i]);
        i++;
    }
    strstr[i] = 0;
    return (strstr);
}

int main(void)
{
    char *str = "   \n   one two three        four \n\n\n     five";
    char **strstr;
    int i;

    i = 0;

    strstr = ft_split(str);
    while (strstr[i])
    {
        printf("%s\n", strstr[i]);
        i++;
    }
    while (i >= 0)
    {
        free(strstr[i]);
        i--;
    }
    free(strstr);
        
}