#include "push_swap.h"

static int count_words(const char *str, char delimiter)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (*str != delimiter && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*str == delimiter)
        {
            in_word = 0;
        }
        str++;
    }
    return count;
}

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char *strdup_split(const char *start, const char *end)
{
    char *word = malloc(end - start + 1);
    if (!word)
        return NULL;
    ft_strncpy(word, start, end - start);
    word[end - start] = '\0';
    return word;
}

char **ft_split(const char *str, char delimiter)
{
    char **result;
    int word_count;
    int i = 0;
    const char *start;

    if (!str)
        return NULL;
    word_count = count_words(str, delimiter);
    result = malloc((word_count + 1) * sizeof(char *));
    if (!result)
        return NULL;
    while (*str)
    {
        if (*str != delimiter)
        {
            start = str;
            while (*str && *str != delimiter)
                str++;
            result[i] = strdup_split(start, str);
            if (!result[i++])
            {
                while (--i >= 0)
                    free(result[i]);
                free(result);
                return NULL;
            }
        }
        else
            str++;
    }
    result[i] = NULL;
    return result;
}


long	ft_atoi(const char *str)
{
	long	res;
	int	isnegative;
	int	i;

	res = 0;
	i = 0;
	isnegative = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		isnegative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += ((int)str[i] - 48);
		i++;
	}
	if (isnegative)
		return (-res);
	else
		return (res);
}
