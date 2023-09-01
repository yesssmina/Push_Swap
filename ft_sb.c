/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:32:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 19:01:11 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_node *lst)
{
	int		swap;

	if (lst && lst->next != NULL)
	{
		swap = lst->value;
		lst->value = lst->next->value;
		lst->next->value = swap;
		ft_putstr_fd("sb\n", 1);
	}
}