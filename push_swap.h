/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:06:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 17:48:28 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "./Libft/libft.h"

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
}					t_node;


void	add_back(t_node **begin, int value);
t_node	*ft_create_pileA(int ac, char **av);
t_node	*ft_sa(t_node *lst);
t_node	*ft_sb(t_node *lst);
t_node	*ft_pa(t_node **pileA, t_node **pileB);
t_node	*ft_pb(t_node **pileA, t_node **pileB);
void ft_ra(t_node **pileA);
void ft_rb(t_node **pileB);



