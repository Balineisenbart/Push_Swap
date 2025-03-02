/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:35:54 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 12:30:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_words(const char *s, char d)
{
    int cnt;
    int in_word;

    cnt = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != d && !in_word)
        {
            in_word = 1;
            cnt++;
        }
        else if (*s == d)
            in_word = 0;
        s++;
    }
    return (cnt);
}
static char *ft_strncpy(char *dst, const char *src, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dst[i] = '\0';
        i++;
    }
    return (dst);
}
static char *strdup_split(const char *start, const char *end)
{
    char *word;

    word = malloc(end - start + 1);
    if (!word)
        return (NULL);
    ft_strncpy(word, start, end - start);
    word[end - start] = '\0';
    return (word);
}
static char **main_split(const char *str, char **res, char d, int i)
{
    const char *start;

    while (*str)
    {
        if (*str != d)
        {
            start = str;
            while (*str && *str != d)
                str++;
            res[i] = strdup_split(start, str);
            if (!res[i])
            {
                while (--i >= 0)
                    free(res[i]);
                return (free(res), NULL);
            }
            i++;
        }
        else
            str++;
    }
    res[i] = NULL;
    return res;
}
char **ft_split(const char *str, char d)
{
    char **res;
    int wc;

    if (!str)
        return (NULL);
    wc = count_words(str, d);
    res = malloc((wc + 1) * sizeof(char *));
    if (!res)
        return (NULL);
    res = main_split(str, res, d, 0);
    return (res);
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
