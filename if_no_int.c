/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_no_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:48:46 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/12 18:48:46 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	if_no_int_free(t_push *push)
{
	while (push->res[push->k] != NULL)
		free(push->res[push->k++]);
	free(push->res);
	free_list(*push->pile_a);
	free_list(*push->pile_b);
	free(push->pile_a);
	free(push->pile_b);
}

long	ft_atoi_long(char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (i != 1 && str[i] == '-' )
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb = sign * nb;
	return (nb);
}

void	if_no_int(t_push *push, char *str)
{
	long	nb;

	nb = ft_atoi_long(str);
	if (ft_strlen(str) > 11)
	{
		if_no_int_free(push);
		error_mess("Error\nAu moins un nombre n'est pas dans la plage int\n");
	}
	if (nb < INT_MIN || nb > INT_MAX)
	{
		if_no_int_free(push);
		error_mess("Error\nAu moins un nombre n'est pas dans la plage int\n");
	}
}
