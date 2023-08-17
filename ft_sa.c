/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:02:08 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 15:24:58 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_sa(t_node *lst)
{
	int		swap;

	if (lst && lst->next != NULL)
	{
		swap = lst->value;
		lst->value = lst->next->value;
		lst->next->value = swap;
	}
	return (lst);
}