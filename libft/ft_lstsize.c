/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:41:47 by lfranca-          #+#    #+#             */
/*   Updated: 2021/06/06 12:59:22 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		n_elem;

	temp = lst;
	n_elem = 0;
	while (temp != NULL)
	{
		n_elem++;
		temp = temp->next;
	}
	return (n_elem);
}
