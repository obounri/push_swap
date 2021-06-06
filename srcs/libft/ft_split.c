/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obounri <obounri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 15:12:40 by obounri           #+#    #+#             */
/*   Updated: 2021/06/06 21:47:50 by obounri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  word_size(char const *s, char c)
{
    int i;
    i = 0;
    while (s[i] != '\0' && s[i] != c)
    {
        i++;
    }
    return (i);
}
static int  words_number(char const *s, char c)
{
    int i;
    int len;
    i = 0;
    len = 0;
    while (s[i] != '\0')
    {
        if ((s[i] != c && s[i + 1] == '\0') || (s[i] != c && s[i + 1] == c))
            len++;
        i++;
    }
    return (len);
}
static void free_tabs(char **tab, int index)
{
    int i;
    i = 0;
    while (i < index)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    tab = NULL;
}
static char **fill(char const *s, char **tab, int leny, char c)
{
    int lenx;
    int x;
    int y;
    y = -1;
    while (++y < leny)
    {
        while (*s == c)
            s++;
        lenx = word_size(s, c);
        x = 0;
        tab[y] = malloc(sizeof(char) * (lenx + 1));
        if (!(tab[y]))
        {
            free_tabs(tab, y);
            return (NULL);
        }
        while (x < lenx)
        {
            tab[y][x++] = *s;
            s++;
        }
        tab[y][x] = '\0';
    }
    return (tab);
}
char    **ft_split(char const *s, char c)
{
    char    **tab;
    int     leny;
    if (!s)
        return (NULL);
    leny = words_number(s, c);
    tab = (char **)malloc(sizeof(char *) * (leny + 1));
    if (!(tab))
        return (NULL);
    tab = fill(s, tab, leny, c);
    if (!(tab))
        return (NULL);
    tab[leny] = 0;
    return (tab);
}