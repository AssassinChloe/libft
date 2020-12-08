/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:22:00 by cassassi          #+#    #+#             */
/*   Updated: 2020/11/30 12:45:54 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

static int	ft_splitlen(const char *s, char c, unsigned int *pi)
{
	int len;

	len = 0;
	while (s[*pi] == c)
		*pi = *pi + 1;
	while (s[len + *pi] && s[len + *pi] != c)
		len++;
	return (len);
}

static char	*ft_strcpy(const char *s, char c, unsigned int *pi)
{
	char			*str;
	unsigned int	j;
	int				len;

	j = 0;
	len = ft_splitlen(s, c, pi);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (s[*pi] && len > 0)
	{
		str[j] = s[*pi];
		j++;
		len--;
		*pi = *pi + 1;
	}
	str[j] = '\0';
	return (str);
}

char		**ft_split(const char *s, char c)
{
	char			**tab;
	unsigned int	*pi;
	unsigned int	i;
	int				j;
	int				len;

	if (!(s))
		return (NULL);
	i = 0;
	pi = &i;
	j = 0;
	len = ft_strcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	if (!(tab))
		return (NULL);
	while (j < len)
	{
		tab[j] = ft_strcpy(s, c, pi);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
