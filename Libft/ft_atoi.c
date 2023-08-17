/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:32:09 by sanaggar          #+#    #+#             */
/*   Updated: 2023/08/16 15:28:30 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char	*str)
{
	int	i;
	int	sign;
	int	nb;

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
/*
int	main(int argc, char	**argv)
{
	argc = 2;
	printf("%d\n", atoi(argv[1]));
	printf("%d\n", ft_atoi(argv[1]));
}*/
