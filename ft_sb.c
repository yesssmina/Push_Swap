/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:32:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 17:14:12 by sannagar         ###   ########.fr       */
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
	}
}