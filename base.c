/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 22:13:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/08 19:33:12 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_create_pile(t_push *push, int ac, char **av)
{
	ft_init_create(push, av);
	if (ac == 2 && ft_strlen(av[push->i]) != ft_strlen(push->res[push->j]))
	{
		while (ac++ && push->res[push->j] != NULL)
			av[push->i++] = push->res[push->j++];
		av[push->i] = NULL;
		ac--;
	}
	push->i = 1;
	while (push->i < ac)
	{
		ft_no_digit(av[push->i]);
		push->valeur = ft_atoi(av[push->i++]);
		add_back(push->pile_a, push->valeur);
	}
	push->j = 0;
	while (push->res[push->j] != NULL)
		free(push->res[push->j++]);
	free(push->res);
	return (*push->pile_a);
}

void	nb_arg(t_push *push)
{
	if (size_pile(*(push->pile_a)) == 2)
	{
		ft_sa(push->pile_a);
		return ;
	}
	if (size_pile(*push->pile_a) == 3 && three_items(push->pile_a) == 1)
		return ;
	if (size_pile(*push->pile_a) == 4
		&& four_items(push->pile_a, push->pile_b) == 1)
		return ;
	if (size_pile(*push->pile_a) == 5
		&& five_items(push->pile_a, push->pile_b) == 1)
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

	tmp_node = *push->pile_a;
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
	free_list((*push->pile_a));
	free_list((*push->pile_b));
	free(push->pile_a);
	free(push->pile_b);
	error_mess("");
}

int	main(int ac, char **av)
{
	t_push	push;

	push.ac1 = ac -1;
	ft_init(&push);
	if (ac < 2)
		return (0);
	*push.pile_a = ft_create_pile(&push, ac, av);
	ft_error_double(*push.pile_a);
	sorted(&push);
	nb_arg(&push);
	if (*push.pile_b != NULL)
		sort_push_a(push.pile_a, push.pile_b);
	free_list(*push.pile_a);
	free_list(*push.pile_b);
	free(push.pile_a);
	free(push.pile_b);
	return (0);
}

/*void	ft_print_pile(t_node *pile)
{
	while (pile != NULL)
	{
		printf("%d\n", pile->value);
		pile = pile->next;
	}
}
puts("pile_a:");
ft_print_pile(*push.pile_a);
puts("pile_b:");
ft_print_pile(*push.pile_b);
*/

	//if (ft_strlen(av[push->i]) == 1)
	//{
	//	free_list(*push->pile_a);
	//	free_list(*push->pile_b);
	//	free(push->pile_a);
	//	free(push->pile_b);
	//	puts("la");
	//	error_mess("");
	//}