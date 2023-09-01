/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/31 02:45:49 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediane_rb(t_node **pileB, t_node *biggest)
{
	while ((*pileB)->value != biggest->value)
	{
		ft_rb(pileB);
		biggest = plus_grand_node(*pileB);
	}
}

void	mediane_rrb(t_node **pileB, t_node *biggest)
{
	while ((*pileB)->value != biggest->value)
	{
		ft_rrb(pileB);
		biggest = plus_grand_node(*pileB);
	}
}

