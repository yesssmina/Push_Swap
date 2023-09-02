/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:34:11 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/02 18:09:16 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	begin_sort_push_b(t_push *push)
{
	if (push->value < push->smallest || push->value > push->until) 
	{
		ft_ra(push->pileA);
		return; 
	}
	if ((*push->pileB) == NULL)
	{
		ft_pb(push->pileA, push->pileB);
		return ;
	}

	while (push->tmp != NULL)
	{
		if (push->value > push->tmp->value)
		{
			push->all_smaller = 0;
			break;
		}
		push->tmp = push->tmp->next;
	}
		if (push->all_smaller)
	{
		ft_pb(push->pileA, push->pileB);
		return ;
	}
}

void	sort_push_b(t_push *push)
{

	ft_init1(push);

	begin_sort_push_b(push);
	
	while ((*push->pileA)->value == push->top_node)
	{

		if (push->top_node > (*push->pileB)->value)
		{
			ft_pb(push->pileA, push->pileB);
			return ;
		}
		else
		{
			ft_rb(push->pileB);
		}
	}
	
}

void	begin_divide(t_push *push)
{
	while (push->top_n != NULL)
	{
		if (push->top_n->value >= push->smallest  && push->top_n->value <= push->until)
			break ;

		push->top_n = push->top_n->next;
		push->count_top++;
	}
	
	while (push->bottom_node->next != NULL)
	push->bottom_node = push->bottom_node->next;

	while (push->bottom_node != NULL)
	{
		if (push->bottom_node->value >= push->smallest && push->bottom_node->value <= push->until)
			break ;

		push->bottom_node = push->bottom_node->prev;
		push->count_bottom++;
	}
}

void	ra_or_rra(t_push *push)
{
	if (push->count_top < push->count_bottom)
	{
		if (*push->pileA && *push->pileA && (*push->pileA)->next)
		{
			while (*push->pileA && (*push->pileA)->value != push->top_n->value)
			{
				ft_ra(push->pileA);
			}
		}
		else
		{
			ft_pb(push->pileA, push->pileB);
			return ;
		}
	}
	if (push->count_top > push->count_bottom)
	{
		while (*push->pileA != NULL && (*push->pileA)->value != push->bottom_node->value)
		{
			ft_rra(push->pileA);
		}
	}
	else
		sort_push_b(push);
}

void	divide_and_push(t_push *push, int	nb_segment)
{
	ft_init2(push, nb_segment);

	while (*push->pileA)
	{
		ft_init3(push);
		
		begin_divide(push);
	
		ra_or_rra(push);
		
		if (push->count_top == push->size && push->count_bottom == push->size)
		{
			//printf("av*****smallest***:%d\n", push->smallest);
			//printf("av*****max******:%d\n", push->until);
			push->smallest = push->until + 1;
			push->until = push->until + push->memo_until + 1;
			//printf("ap*****smallest***:%d\n", push->smallest);
			//printf("ap*****max******:%d\n", push->until);
		}
	}
}