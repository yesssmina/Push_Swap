/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:34:11 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 18:55:05 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	max_segment(int size_pile, int nb_segment) 
{
    int	segment_size;

	segment_size = size_pile / nb_segment;

    return (segment_size - 1);
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
		//ft_putstr_fd("pa\n", 1);

	}
}

void	sort_push_b(t_node **pileA, t_node **pileB, int smallest, int seg_until)
{
	t_node	*tmp;
	int		top_node;
	int		value;
	int		all_smaller;
	
	value = (*pileA)->value;
	top_node = (*pileA)->value;
	tmp = *pileB;
	all_smaller = 1;

	if (value < smallest || value > seg_until) 
	{
		ft_ra(pileA);
		return; 
	}
	if (*pileB == NULL)
	{
		ft_pb(pileA, pileB);
		//ft_putstr_fd("pb\n", 1);
		return ;
	}

	while (tmp != NULL)
	{
		if (value > tmp->value)
		{
			all_smaller = 0;
			break;
		}
		tmp = tmp->next;
	}

	if (all_smaller)
	{
		ft_pb(pileA, pileB);
		return ;
	}
	
	while ((*pileA)->value == top_node)
	{

		if (top_node > (*pileB)->value)
		{
			ft_pb(pileA, pileB);
			return ;
		}
		else
		{
			ft_rb(pileB);
		}
	}
	
}


void	divide_and_push(t_node **pileA, t_node **pileB, int	nb_segment)
{
	t_node	*top_node;
	t_node	*bottom_node;

	int		smallest;
	int		count_top;
	int		count_bottom;
	int		size;
	int		segment_until;
	int		memo_segment_until;

	smallest = plus_petit_node(*pileA)->value;
	size = size_pileA(*pileA);
	segment_until = max_segment(size, nb_segment);
	memo_segment_until = segment_until;
	while (*pileA)
	{
		size = size_pileA(*pileA);
		top_node = *pileA;
		bottom_node = *pileA;
		count_top = 0;
		count_bottom = 0;
		

		//printf("*****smallest***:%d\n", smallest);
		//printf("*****max******:%d\n", segment_until);
		while (top_node != NULL)
		{
			if (top_node->value >= smallest  && top_node->value <= segment_until)
				break ;

			top_node = top_node->next;
			count_top++;
		}
		
		while (bottom_node->next != NULL)
			bottom_node = bottom_node->next;

		while (bottom_node != NULL)
		{
			if (bottom_node->value >= smallest && bottom_node->value <= segment_until)
				break ;

			bottom_node = bottom_node->prev;
			count_bottom++;
		}
		
		if (count_top < count_bottom)
		{
			if (*pileA && *pileA && (*pileA)->next)
			{
				while (*pileA && (*pileA)->value != top_node->value)
				{
					ft_ra(pileA);
				}
			}
			else
			{
				ft_pb(pileA, pileB);
				return ;
			}

		}
		if (count_top > count_bottom)
		{
			while (*pileA != NULL && (*pileA)->value != bottom_node->value)
			{
				ft_rra(pileA);
				//ft_putstr_fd("rra", 1);
			}
			
		}
		else
		{
			//puts("BAHLA");
			sort_push_b(pileA, pileB, smallest, segment_until);
		}
		if (count_top == size && count_bottom == size)
		{
			smallest = segment_until + 1;
			segment_until = segment_until + memo_segment_until + 1;
		}
	}
}
		//printf("size:%d\n", size);
		//printf("top_count:%d\n", count_top);
		//printf("bottom_count:%d\n", count_bottom);

			//puts("**********la?");
			//printf("value:%d\n", value);
			//printf("tmp:%d\n", tmp->value);
		//puts("pileA:");
		//ft_print_pile(*pileA);
		//puts("pileB:");
		//ft_print_pile(*pileB);

			//printf("size:%d\n", size_pile);
	//printf("debut_segment:%d\n", debut_segment);
	//printf("nb_segment:%d\n", nb_segment);
	//printf("seg_size:%d\n", segment_size);