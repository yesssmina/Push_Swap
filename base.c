/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 04:13:26 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_pile(t_push *push, int ac, char **av)
{
	ft_init_create(push, av);
	if (ac == 2 && ft_strlen(av[push->i]) != ft_strlen(push->res[push->j]))
	{
		while (push->res[push->j] != NULL)
		{
			av[push->i++] = push->res[push->j++];
			ac++;
		}
		av[push->i] = NULL;
		ac--;
	}
	push->i = 1;
	while (push->i < ac)
	{
		ft_no_digit(av[push->i]);
		push->valeur = ft_atoi(av[push->i++]);
		add_back(push->pileA, push->valeur);
	}
	push->j = 0;
	while (push->res[push->j] != NULL)
		free(push->res[push->j++]);
	free(push->res);
	return (*push->pileA);
}

void	ft_print_pile(t_node *pile)
{
	while (pile != NULL)
	{
		printf("%d\n", pile->value);
		pile = pile->next;
	}
}

void	nb_arg(t_push *push)
{
	if (size_pile(*(push->pileA)) == 2)
	{
		ft_sa(push->pileA);
		return ;
	}
	if (size_pile(*push->pileA) == 3 && three_items(push->pileA) == 1)
		return ;
	if (size_pile(*push->pileA) == 4
		&& four_items(push->pileA, push->pileB) == 1)
		return ;
	if (size_pile(*push->pileA) == 5
		&& five_items(push->pileA, push->pileB) == 1)
		return ;
	if (push->ac1 < 101)
	{
		push->ac1 = 5;
		divide_and_push(push, push->ac1);
	}
	else
	{
		push->ac1 = 11;
		divide_and_push(push, push->ac1);
	}
}

void	sorted(t_push *push)
{
	t_node	*tmp_node;
	int		tmp;

	tmp_node = *push->pileA;
	tmp = tmp_node->value;
	while ((tmp_node)->next != NULL)
	{
		if (tmp_node->next->value > tmp)
		{
			tmp = tmp_node->next->value;
			tmp_node = tmp_node->next;
		}
		else
			return ;
	}
	free_list((*push->pileA));
	free_list((*push->pileB));
	free(push->pileA);
	free(push->pileB);
	error_mess("");
}

int	main(int ac, char **av)
{
	t_push	push;

	push.ac1 = ac -1;
	ft_init(&push);
	if (ac < 2)
		return (0);
	*push.pileA = ft_create_pile(&push, ac, av);
	ft_error_double(*push.pileA);
	sorted(&push);
	nb_arg(&push);
	if (*push.pileB != NULL)
		sort_push_a(push.pileA, push.pileB);
	free_list(*push.pileA);
	free_list(*push.pileB);
	free(push.pileA);
	free(push.pileB);
	return (0);
}

	//puts("pileA:");
	//ft_print_pile(*push.pileA);
	//puts("pileB:");
	//ft_print_pile(*push.pileB);

//casser les fonction
//verif .h Makefile
