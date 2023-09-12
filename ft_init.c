/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:02:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/09 18:29:35 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_push *push)
{
	push->pile_a = malloc(sizeof(t_node *));
	push->pile_b = malloc(sizeof(t_node *));
	if (!push->pile_a || !push-> pile_b)
		error_mess("Error\nL'allocation de 'pile_b' ou 'pile_a' a echouee\n");
	*push->pile_a = NULL;
	*push->pile_b = NULL;
}

void	ft_init1(t_push *push)
{
	push->value = (*push->pile_a)->value;
	push->top_node = (*push->pile_a)->value;
	push->tmp = (*push->pile_b);
	push->all_smaller = 1;
}

void	ft_init2(t_push *push, int nb_seg)
{
	push->smallest = plus_petit_node(*push->pile_a)->value;
	push->size = size_pile(*push->pile_a);
	push->until = max_segment(push->size, nb_seg);
	push->memo_until = push->until;
}

void	ft_init3(t_push *push)
{
	push->size = size_pile(*push->pile_a);
	push->top_n = *push->pile_a;
	push->bottom_node = *push->pile_a;
	push->count_top = 0;
	push->count_bottom = 0;
}

void	ft_init_create(t_push *push, char **av)
{
	push->pile = NULL;
	push->valeur = 0;
	push->i = 1;
	push->j = 0;
	push->k = 0;
	push->res = ft_split(av[push->i], ' ');
	if (!push->res)
		error_mess("Error\nL'implementation de 'res' a echouee\n");
	if (!push->res[push->j])
	{
		free(push->pile_a);
		free(push->pile_b);
		free(push->res);
		error_mess("Error\nLa liste doit contenir que des nombres\n");
	}
}
