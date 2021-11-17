/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 02:26:09 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:45:13 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	leng;

	leng = ft_strlen(s);
	while (leng)
	{
		if (s[leng] == (unsigned char)c)
			return ((char *)&s[leng]);
		leng--;
	}
	if (s[leng] == (unsigned char)c)
		return ((char *)&s[leng]);
	return (NULL);
}
