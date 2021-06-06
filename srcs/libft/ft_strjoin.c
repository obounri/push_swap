/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unixpassword <unixpassword@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 21:28:30 by obounri           #+#    #+#             */
/*   Updated: 2021/06/05 22:27:41 by unixpasswor      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*j;
	unsigned int	i;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 || !s2)
		return (0);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	j = malloc(l1 + l2 + 1);
	if (!j)
		return (0);
	ft_bzero(j, l1 + l2 + 1);
	i = 0;
	while (s1[i] != '\0')
	{
		j[i] = s1[i];
		i++;
	}
	j = ft_strcat(j, s2);
	return (j);
}