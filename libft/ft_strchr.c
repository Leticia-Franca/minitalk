/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:26:14 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/01 17:49:53 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*ptr_s;

	i = 0;
	ptr_s = (char *)s;
	len = ft_strlen(ptr_s);
	while (i < len)
	{
		if (ptr_s[i] == (char)c)
		{
			return (&ptr_s[i]);
		}
		i++;
	}
	if (ptr_s[i] == (char)c)
		return (&ptr_s[i]);
	else
		return (NULL);
}
