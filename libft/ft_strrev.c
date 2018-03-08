/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:27:49 by bede-fre          #+#    #+#             */
/*   Updated: 2018/01/24 14:01:28 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tp;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	tp = 0;
	while (i < (len / 2))
	{
		tp = str[i];
		str[i] = str[(len - 1) - i];
		str[(len - 1) - i] = tp;
		i++;
	}
}