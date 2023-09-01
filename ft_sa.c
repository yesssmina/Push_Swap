/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:02:08 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 19:01:18 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_node *lst)
{
	int		swap;

	if (lst && lst->next != NULL)
	{
		swap = lst->value;
		lst->value = lst->next->value;
		lst->next->value = swap;
		ft_putstr_fd("sa", 1);
	}
}