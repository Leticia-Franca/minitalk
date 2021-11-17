/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:15:40 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:35:52 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = -1;
	if (!src && !dest)
		return (0);
	if (s < d)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
	{
		while (++i < n)
		{
			*d++ = *s++;
		}
	}
	return (dest);
}
