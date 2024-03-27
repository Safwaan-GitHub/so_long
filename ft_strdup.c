/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanoor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:18:03 by sanoor            #+#    #+#             */
/*   Updated: 2024/03/27 22:18:48 by sanoor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	char	*str;
	int		len;
	int		count;

	count = 0;
	str = (char *)s;
	len = ft_strlen(str) + 1;
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	while (count < len)
	{
		res[count] = str[count];
		count++;
	}
	res[len] = '\0';
	return (res);
}
