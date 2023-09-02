/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/02 18:00:06 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *ft_create_pileA(int ac, char **av)
{
	t_node  *pileA;
	int     value;
	int     i;
	
	pileA = NULL;
	value = 0;
	i = 1;

	while (i < ac)  
	{
		value = ft_atoi(av[i]);
		add_back(&pileA, value);
		i++;
	}
	return (pileA);
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
	if (push->ac1 < 5)
	{
		divide_and_push(push, push->ac1);
		return ;
	}
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




int main(int ac, char **av)
{
	t_push	push;

	push.ac1 = ac -1;
	ft_init(&push);

	if (ac < 2)
		return (0);

	*push.pileA = ft_create_pileA(ac, av);
	
	if (ft_error_double((*push.pileA)) == 1)
	{
		ft_putstr_fd("Error, doublon\n", 1);
		return (0);
	}

	nb_arg(&push);
	sort_push_a(push.pileA, push.pileB);
	//puts("pileA:");
	//ft_print_pile(*push.pileA);
	//puts("pileB:");
	//ft_print_pile(*push.pileB);
	free_list(*push.pileA);
	free_list(*push.pileB);
	free(push.pileA);
	free(push.pileB);
	
	return (0);
}

//gerer les cas
//gerer si la liste est en ordre
//gerer si il y a que un nb
//mettre a la norme
//casser les fonctions