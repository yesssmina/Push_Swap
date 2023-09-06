/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:54:34 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_biggest(t_node **pile_a, int smallest)
{
	if ((*pile_a)->next->value == smallest)
		ft_ra(pile_a);
	else
	{
		ft_ra(pile_a);
		ft_sa(pile_a);
	}
}

int	three_items(t_node **pile_a)
{
	int	smallest;
	int	biggest;

	smallest = plus_petit_node(*pile_a)->value;
	biggest = plus_grand_node(*pile_a)->value;
	if ((*pile_a)->value == smallest)
	{
		ft_rra(pile_a);
		ft_sa(pile_a);
		return (1);
	}
	if ((*pile_a)->value == biggest)
	{
		if_biggest(pile_a, smallest);
		return (1);
	}
	if ((*pile_a)->value != biggest && (*pile_a)->value != smallest)
	{
		if ((*pile_a)->next->value == smallest)
			ft_sa(pile_a);
		else
			ft_rra(pile_a);
		return (1);
	}
	return (0);
}

int	four_items(t_node **pile_a, t_node **pile_b)
{
	int	smallest;

	smallest = plus_petit_node(*pile_a)->value;
	if ((*pile_a)->next->value == smallest)
		ft_ra(pile_a);
	else if ((*pile_a)->next->next->value == smallest)
	{
		ft_ra(pile_a);
		ft_ra(pile_a);
	}
	else if ((*pile_a)->next->next->next->value == smallest)
		ft_rra(pile_a);
	if (!(*pile_b) && gia_sorted(pile_a))
		return (1);
	if (gia_sorted(pile_a) == 1)
	{
		ft_pa(pile_a, pile_b);
		return (1);
	}
	ft_pb(pile_a, pile_b);
	three_items(pile_a);
	ft_pa(pile_a, pile_b);
	return (1);
}

int	gia_sorted(t_node **pile_a)
{
	t_node	*tmp_node;
	int		tmp;

	tmp_node = *pile_a;
	tmp = tmp_node->value;
	while ((tmp_node)->next != NULL)
	{
		if (tmp_node->next->value > tmp)
		{
			tmp = tmp_node->next->value;
			tmp_node = tmp_node->next;
		}
		else
			return (0);
	}
	return (1);
}

int	five_items(t_node **pile_a, t_node **pile_b)
{
	int	smallest;

	smallest = plus_petit_node(*pile_a)->value;
	if ((*pile_a)->next->value == smallest)
		ft_ra(pile_a);
	else if ((*pile_a)->next->next->value == smallest)
		twice_ra(pile_a);
	else if ((*pile_a)->next->next->next->value == smallest)
		twice_rra(pile_a);
	else if ((*pile_a)->next->next->next->next->value == smallest)
		ft_rra(pile_a);
	if (gia_sorted(pile_a))
		return (1);
	ft_pb(pile_a, pile_b);
	four_items(pile_a, pile_b);
	if (*pile_b)
	{
		ft_pa(pile_a, pile_b);
		ft_pa(pile_a, pile_b);
	}
	return (1);
}
