/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:54:34 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 02:40:02 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_biggest(t_node **pileA, int smallest)
{
	if ((*pileA)->next->value == smallest)
			ft_ra(pileA);
		else
		{
			ft_ra(pileA);
			ft_sa(pileA);
		}
}

int	three_items(t_node **pileA)
{
	int	smallest;
	int	biggest;

	smallest = plus_petit_node(*pileA)->value;
	biggest = plus_grand_node(*pileA)->value;

	if ((*pileA)->value == smallest)
	{
		ft_rra(pileA);
		ft_sa(pileA);
		return (1);
	}

	if ((*pileA)->value == biggest)
	{
		if_biggest(pileA, smallest);
		return (1);
	}
	
	if ((*pileA)->value != biggest && (*pileA)->value != smallest)
	{
		if ((*pileA)->next->value == smallest)
			ft_sa(pileA);
		else
			ft_rra(pileA);
		return (1);
	}
	return (0);
}

int	four_items(t_node **pileA, t_node **pileB)
{
	int	smallest;

	smallest = plus_petit_node(*pileA)->value;

	if ((*pileA)->next->value == smallest)
		ft_ra(pileA);

	else if ((*pileA)->next->next->value == smallest)
	{
		ft_ra(pileA);
		ft_ra(pileA);
	}
	else if ((*pileA)->next->next->next->value == smallest)
		ft_rra(pileA);
	
	if (!(*pileB) && gia_sorted(pileA))
		return (1);
	if (gia_sorted(pileA) == 1)
	{
		ft_pa(pileA, pileB);
		return (1);
	}
	ft_pb(pileA, pileB);
	three_items(pileA);
	ft_pa(pileA, pileB);
	return (1);
}

int	gia_sorted(t_node **pileA)
{
	t_node	*tmp_node;
	int	tmp;

	tmp_node = *pileA;
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

int	five_items(t_node **pileA, t_node **pileB)
{
	int	smallest;

	smallest = plus_petit_node(*pileA)->value;

	if ((*pileA)->next->value == smallest)
		ft_ra(pileA);

	else if ((*pileA)->next->next->value == smallest)
	{
		ft_ra(pileA);
		ft_ra(pileA);
	}
	else if ((*pileA)->next->next->next->value == smallest)
	{
		ft_rra(pileA);
		ft_rra(pileA);
	}
	else if ((*pileA)->next->next->next->next->value == smallest)
		ft_rra(pileA);
	
	if (gia_sorted(pileA))
		return (1);
	ft_pb(pileA, pileB);
	four_items(pileA, pileB);
	if (*pileB)
	{
		ft_pa(pileA, pileB);
		ft_pa(pileA, pileB);
	}
	return (1);
}





//t_node	*second_plus_petit_node(t_node *pileA, int smallest)
//{
//	t_node	*plus_petit;

//	if (pileA->value != smallest)
//		plus_petit = pileA;
//	else
//		plus_petit = pileA->next;

//	while (pileA)
//	{
//		if (pileA->value != smallest && pileA->value < plus_petit->value)
//			plus_petit = pileA;
//		pileA = pileA->next;
//	}
//	return (plus_petit);
//}