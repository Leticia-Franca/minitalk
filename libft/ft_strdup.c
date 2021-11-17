/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 07:00:16 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:40:28 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	char	*p;
	int		i;

	i = 0;
	p = (char *)s;
	new_s = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new_s == NULL)
		return (NULL);
	while (p[i] != '\0')
	{
		new_s[i] = p[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
