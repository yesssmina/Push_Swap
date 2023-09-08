/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:24:22 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/08 20:57:27 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

int	ft_error_double(t_push *push, t_node *pile_a)
{
	t_node	*doublon;
	t_node	*tmp;

	doublon = pile_a;
	while (doublon)
	{
		tmp = doublon->next;
		while (tmp)
		{
			if (doublon->value == tmp->value)
			{
				free_list(*push->pile_a);
				free_list(*push->pile_b);
				free(push->pile_a);
				free(push->pile_b);
				error_mess("Error\nDoublon\n");
			}
			tmp = tmp->next;
		}
		doublon = doublon->next;
	}
	return (0);
}

void	if_no_digit_free(t_push *push)
{
	while (push->res[push->k] != NULL)
		free(push->res[push->k++]);
	free(push->res);
	free_list(*push->pile_a);
	free_list(*push->pile_b);
	free(push->pile_a);
	free(push->pile_b);
	error_mess("Error\nIl n'y a pas que des nombres\n");
}

int	ft_no_digit(t_push *push, char *str)
{
	push->k = 0;
	if (*str == '-')
		str++;
	if (*str == '\0')
	{
		if_no_digit_free(push);
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			if_no_digit_free(push);
		}
		str++;
	}
	return (0);
}
