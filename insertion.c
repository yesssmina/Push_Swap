/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/02 18:06:17 by sannagar         ###   ########.fr       */
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

int	max_segment(int size_pile, int nb_segment) 
{
    int	segment_size;

	segment_size = size_pile / nb_segment;

    return (segment_size);
}

t_node	*plus_grand_node(t_node *pileB)
{
	t_node	*plus_grand;

	plus_grand = pileB;

	while (pileB)
	{
		if (pileB->value > plus_grand->value)
			plus_grand = pileB;
		pileB = pileB->next;
	}
	return (plus_grand);
}

void	sort_push_a(t_node **pileA, t_node **pileB)
{
	t_node	*biggest;
	int		size;
	int		mediane;
	int		position;

	while (*pileB)
	{
		biggest = plus_grand_node(*pileB);
		size = size_pileA(*pileB);
		mediane = size / 2;
		position = biggest_place(*pileB, biggest);

		if (position <= mediane)
			mediane_rb(pileB, biggest);
		else
		{
			mediane_rrb(pileB, biggest);
		}
		ft_pa(pileA, pileB);
	}
}
