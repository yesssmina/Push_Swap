/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 19:31:37 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_double(t_node *pileA)
{
	t_node	*doublon;
	t_node	*tmp;

	doublon = pileA;

	while (doublon)
	{
		tmp = doublon->next;

		while (tmp)
		{
			if (doublon->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		doublon = doublon->next;
	}
	return (0);
}

void   add_back(t_node **begin, int value)
{
	t_node  *current;
	t_node  *new_node;

	new_node = malloc(sizeof(t_node));
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

//t_node	*ft_create_pileB(t_node *pileB)
//{
//	pileB = malloc(sizeof(t_node));
//	pileB = NULL;

//	return (pileB);
//}

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

	sort(&pileA, &pileB);
	puts("pileA:");
	ft_print_pile(pileA);
	puts("pileB:");
	ft_print_pile(pileB);
	free_list(pileA);
	
	return (0);
}
