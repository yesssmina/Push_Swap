/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:21:44 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 18:48:03 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node *list)
{
	t_node	*tmp;

	//tmp = list;

	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	//free(list);
}