/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:34:11 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_sort_push_b(t_push *push)
{
	if ((push->value > push->until))
	{
		ft_ra(push->pile_a);
		return ;
	}
	if ((*push->pile_b) == NULL)
	{
		ft_pb(push->pile_a, push->pile_b);
		return ;
	}
	while (push->tmp != NULL)
	{
		if (push->value > push->tmp->value)
		{
			push->all_smaller = 0;
			break ;
		}
		push->tmp = push->tmp->next;
	}
	if (push->all_smaller)
	{
		ft_pb(push->pile_a, push->pile_b);
		return ;
	}
}

void	sort_push_b(t_push *push)
{
	ft_init1(push);
	begin_sort_push_b(push);
	while ((*push->pile_a)->value == push->top_node)
	{
		if (push->top_node > (*push->pile_b)->value)
		{
			ft_pb(push->pile_a, push->pile_b);
			return ;
		}
		else
			ft_rb(push->pile_b);
	}
}

void	begin_divide(t_push *push)
{
	while (push->top_n != NULL)
	{
		if (push->top_n->value >= push->smallest
			&& push->top_n->value <= push->until)
			break ;
		push->top_n = push->top_n->next;
		push->count_top++;
	}
	while (push->bottom_node->next != NULL)
		push->bottom_node = push->bottom_node->next;
	while (push->bottom_node != NULL)
	{
		if (push->bottom_node->value >= push->smallest
			&& push->bottom_node->value <= push->until)
			break ;
		push->bottom_node = push->bottom_node->prev;
		push->count_bottom++;
	}
}

void	ra_or_rra(t_push *push)
{
	if (push->count_top < push->count_bottom)
	{
		if (*push->pile_a && (*push->pile_a)->next)
		{
			while (*push->pile_a && (*push->pile_a)->value != push->top_n->value)
				ft_ra(push->pile_a);
		}
		else
		{
			if ((*push->pile_a)->value > (*push->pile_a)->next->value)
			{
				ft_pb(push->pile_a, push->pile_b);
				return ;
			}
			else
			{
				ft_ra(push->pile_a);
				ft_pb(push->pile_a, push->pile_b);
				return ;
			}
		}
	}
}

void	divide_and_push(t_push *push, int nb_segment)
{
	ft_init2(push, nb_segment);
	while (*push->pile_a)
	{
		ft_init3(push);
		begin_divide(push);
		ra_or_rra(push);
		if (push->count_top > push->count_bottom)
		{
			while (*push->pile_a != NULL
				&& (*push->pile_a)->value != push->bottom_node->value)
				ft_rra(push->pile_a);
		}
		else
			sort_push_b(push);
		if (push->count_top == push->size && push->count_bottom == push->size)
		{
			push->smallest = push->until + 1;
			push->until = push->until + push->memo_until + 1;
		}
	}
}
