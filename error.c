/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:24:22 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 18:19:23 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*error_mess(char *message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

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
				error_mess("Error\nDoublon\n");
			tmp = tmp->next;
		}
		doublon = doublon->next;
	}
	return (0);
}

int	ft_no_digit(char *str)
{
	if (*str == '-')
		str++;
	if (*str == '\0')
		error_mess("Error\nIl n'y a pas que des nombres\n");
	while (*str)
	{
		if (!ft_isdigit(*str))
			error_mess("Error\nIl n'y a pas que des nombres\n");
		str++;
	}
	return (0);
}
