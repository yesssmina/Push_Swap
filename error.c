/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:24:22 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/02 17:27:23 by sannagar         ###   ########.fr       */
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