/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:16:16 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 22:03:17 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (((s1[i] != '\0' || s2[i] != '\0')
			&& (s1[i] == s2[i]) && (i < n - 1)))
		i++;
	return (*(const unsigned char *)&s1[i] - *(const unsigned char *)&s2[i]);
}
