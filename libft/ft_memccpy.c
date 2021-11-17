/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:15:18 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:24:19 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while ((unsigned char)s[i] != (unsigned char)c && i < n)
	{
		d[i] = s[i];
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c && i < n)
	{
		d[i] = s[i];
		i++;
		return (&d[i]);
	}
	else
		return (NULL);
}
