/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:15:36 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:32:25 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destin;
	char	*source;

	if (!dest && !src)
		return (NULL);
	destin = (char *)dest;
	source = (char *)src;
	i = 0;
	while (i < n)
	{
		destin[i] = source[i];
		i++;
	}
	return (dest);
}
