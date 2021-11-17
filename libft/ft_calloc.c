/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 06:17:23 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:19:53 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*ptrmem;

	i = nmemb * size;
	ptrmem = malloc(i);
	if (!ptrmem)
		return (NULL);
	ft_bzero(ptrmem, i);
	return (ptrmem);
}
