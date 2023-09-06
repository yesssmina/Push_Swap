/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:43:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_node **pile_a, t_node **pile_b)
{
	int		value;
	t_node	*tmp;
	t_node	*new_node;

	if (*pile_b)
	{
		value = (*pile_b)->value;
		tmp = *pile_b;
		*pile_b = (*pile_b)->next;
		free(tmp);
		new_node = malloc(sizeof(t_node));
		new_node->value = value;
		new_node->next = *pile_a;
		*pile_a = new_node;
		ft_putstr_fd("pa\n", 1);
	}
}
