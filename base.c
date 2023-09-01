/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 20:31:08 by sannagar         ###   ########.fr       */
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

void	nb_arg(t_node **pileA, t_node **pileB, int	ac)
{
	if (ac < 5)
	{
		printf("nb_arg:%d\n", ac);
		divide_and_push(pileA, pileB, ac);
		return ;
	}

	if (ac < 101)
		divide_and_push(pileA, pileB, 5);
	else
		divide_and_push(pileA, pileB, 11);
}
int main(int ac, char **av)
{
	t_node *pileA;
	t_node *pileB;

	if (ac < 2)
		return (0);

	pileA = ft_create_pileA(ac, av);
	pileB = NULL;
	
	if (ft_error_double(pileA) == 1)
	{
		ft_putstr_fd("Error, doublon\n", 1);
		return (0);
	}

	nb_arg(&pileA, &pileB, ac -1);
	sort_push_a(&pileA, &pileB);
	//puts("pileA:");
	//ft_print_pile(pileA);
	//puts("pileB:");
	//ft_print_pile(pileB);
	free_list(pileA);
	free_list(pileB);
	
	return (0);
}

//gerer les cas
//gerer si la liste est en ordre
//gerer si il y a que un nb
//mettre a la norme
//casser les fonctions