/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediane_rb(t_node **pile_b, t_node *biggest)
{
	while ((*pile_b)->value != biggest->value)
	{
		ft_rb(pile_b);
		biggest = plus_grand_node(*pile_b);
	}
}

void	mediane_rrb(t_node **pile_b, t_node *biggest)
{
	while ((*pile_b)->value != biggest->value)
	{
		ft_rrb(pile_b);
		biggest = plus_grand_node(*pile_b);
	}
}

int	max_segment(int size_pile, int nb_segment)
{
	int	segment_size;

	segment_size = size_pile / nb_segment;
	return (segment_size);
}

t_node	*plus_grand_node(t_node *pile_b)
{
	t_node	*plus_grand;

	plus_grand = pile_b;
	while (pile_b)
	{
		if (pile_b->value > plus_grand->value)
			plus_grand = pile_b;
		pile_b = pile_b->next;
	}
	return (plus_grand);
}

void	sort_push_a(t_node **pile_a, t_node **pile_b)
{
	t_node	*biggest;
	int		size;
	int		mediane;
	int		position;

	while (*pile_b)
	{
		biggest = plus_grand_node(*pile_b);
		size = size_pile(*pile_b);
		mediane = size / 2;
		position = biggest_place(*pile_b, biggest);
		if (position <= mediane)
			mediane_rb(pile_b, biggest);
		else
			mediane_rrb(pile_b, biggest);
		ft_pa(pile_a, pile_b);
	}
}
