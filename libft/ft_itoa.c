/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 00:53:34 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/06 20:26:24 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digt(int n)
{
	size_t	ct;

	ct = 0;
	if (n == 0)
		ct++;
	while (n != 0)
	{
		n /= 10;
		ct++;
	}
	return (ct);
}

char	*ft_itoa(int n)
{
	char		*num_str;
	size_t		dgt;
	long int	numb;

	numb = n;
	dgt = ft_digt(n);
	if (n < 0)
	{
		numb *= -1;
		dgt++;
	}
	num_str = (char *)malloc(sizeof(char) * (dgt + 1));
	if (!num_str)
		return (NULL);
	num_str[dgt] = '\0';
	while (dgt--)
	{
		num_str[dgt] = numb % 10 + '0';
		numb /= 10;
	}
	if (n < 0)
		num_str[0] = '-';
	return (num_str);
}
