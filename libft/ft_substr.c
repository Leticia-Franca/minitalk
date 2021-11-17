/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:40:23 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/09 21:57:38 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	s_leng;

	if (!s)
		return (NULL);
	s_leng = ft_strlen(s);
	if (s == NULL || s_leng <= start)
		return (ft_strdup(""));
	if (start + len < s_leng)
		new_string = (char *)malloc(sizeof(char) * (len + 1));
	else
		new_string = (char *)malloc(sizeof(char) * (s_leng - start + 1));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
