/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:02:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 04:12:13 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_push *push)
{
	push->pileA = malloc(sizeof(t_node *));
	push->pileB = malloc(sizeof(t_node *));
	if (!push->pileA || !push-> pileB)
		return ;
	*push->pileA = NULL;
	*push->pileB = NULL;
}

void	ft_init1(t_push *push)
{
	push->value = (*push->pileA)->value;
	push->top_node = (*push->pileA)->value;
	push->tmp = (*push->pileB);
	push->all_smaller = 1;
}

void	ft_init2(t_push *push, int nb_seg)
{
	push->smallest = plus_petit_node(*push->pileA)->value;
	push->size = size_pile(*push->pileA);
	push->until = max_segment(push->size, nb_seg);
	push->memo_until = push->until;
}

void	ft_init3(t_push *push)
{
	push->size = size_pile(*push->pileA);
	push->top_n = *push->pileA;
	push->bottom_node = *push->pileA;
	push->count_top = 0;
	push->count_bottom = 0;
}

void	ft_init_create(t_push *push, char **av)
{
	push->pile = NULL;
	push->valeur = 0;
	push->i = 1;
	push->j = 0;
	push->res = ft_split(av[push->i], ' ');
	if (!push->res)
		return ;
}
