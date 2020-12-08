/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:38:58 by cassassi          #+#    #+#             */
/*   Updated: 2020/11/30 12:54:55 by cassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int i;

	i = 0;
	if (!(s))
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
