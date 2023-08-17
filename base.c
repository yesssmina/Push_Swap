/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 17:52:17 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   add_back(t_node **begin, int value)
{
	t_node  *current;
	t_node  *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;

	new_node->value = value;
	new_node->next = NULL;

	if (*begin == NULL)  // Si la liste est vide, ajoute le premier nœud
	{
		*begin = new_node;
		return ;
	}
	
	current = *begin;

	while (current->next != NULL)
		current = current->next;

	current->next = new_node;
	
}

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

int main(int ac, char **av)
{
	t_node *pileA;
	//t_node *pileB;

	if (ac < 2)
		return (0);

	pileA = ft_create_pileA(ac, av);
	//pileB = ft_create_pileA(ac, av);
	ft_ra(&pileA);
	ft_print_pile(pileA);
	
	return (0);
}
