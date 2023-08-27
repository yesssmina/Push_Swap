/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/27 17:41:47 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mediane_ra(t_node **pileA, t_node *smallest)
{
	while ((*pileA)->value != smallest->value)
	{
		ft_ra(pileA);
		smallest = plus_petit_node(*pileA);
		ft_putstr_fd("ra\n", 1);
	}
}

void	mediane_rra(t_node **pileA, t_node *smallest)
{
	while ((*pileA)->value != smallest->value)
	{
		ft_rra(pileA);
		smallest = plus_petit_node(*pileA);
		ft_putstr_fd("rra\n", 1);
	}
}

void	sort(t_node **pileA, t_node **pileB)
{
	t_node	*smallest;
	int		size;
	int		mediane;
	int		position;

	while (*pileA != NULL)
	{
		smallest = plus_petit_node(*pileA);
		size = size_pileA(*pileA);
		mediane = size / 2;
		position = smallest_place(*pileA, smallest);

		if (position <= mediane)
			mediane_ra(pileA, smallest);
		else
			mediane_rra(pileA, smallest);
		ft_pb(pileA, pileB);
		ft_putstr_fd("pb\n", 1);
	}

	while (*pileB != NULL)
	{
		ft_pa(pileA, pileB);
		ft_putstr_fd("pa\n", 1);
	}
}

int calculate_operations(t_node *pileA, t_node *node, int is_top)
{
    if (node == NULL)
        return INT_MAX;
    
    int position = smallest_place(pileA, node);
    return is_top ? size_pileA(pileA) - position : position;
}

void perform_rotations(t_node **pileA, int count, int is_ra)
{
    for (int i = 0; i < count; i++)
    {
        if (is_ra)
        {
            ft_ra(pileA);
            ft_putstr_fd("ra\n", 1);
        }
        else
        {
            ft_rra(pileA);
            ft_putstr_fd("rra\n", 1);
        }
    }
}

//void divide_and_push(t_node **pileA, t_node **pileB, int segment_size )
//{
//    while (*pileA != NULL)
//    {
//        t_node	*top_node = *pileA;
//        t_node	*bottom_node = *pileA;
//		t_node	*current;
//		int		operations_top;
//		int		operations_bottom;
//        int		i = 0;
//		int		count;

//        while (i < segment_size && top_node != NULL)
//        {
//            top_node = top_node->next;
//            i++;
//        }

//        i = 0;
//        while (i < segment_size && bottom_node != NULL)
//        {
//            bottom_node = bottom_node->prev;
//            i++;
//        }

//        operations_top = calculate_operations(*pileA, top_node, 1);
//        operations_bottom = calculate_operations(*pileA, bottom_node, 0);

//        if (operations_top <= operations_bottom)
//        {
//            current = *pileA;
//            count = 0;
//            while (current != top_node)
//            {
//                count++;
//                current = current->next;
//            }
//            perform_rotations(pileA, count, 1);
//        }
//        else
//        {
//            current = *pileA;
//            count = 0;
//            while (current != bottom_node && current != NULL)
//            {
//                count++;
//                current = current->prev;
//            }
//            perform_rotations(pileA, count, 0);
//        }

//        if (operations_top <= operations_bottom)
//        {
//            ft_pb(pileA, pileB);
//            ft_putstr_fd("pb\n", 1);
//        }
//    }
//}




// continuer
