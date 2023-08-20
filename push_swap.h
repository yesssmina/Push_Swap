/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:06:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 17:59:39 by sannagar         ###   ########.fr       */
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
void	add_front(t_node **begin, int value);
t_node	*ft_create_pileA(int ac, char **av);
void	ft_print_pile(t_node *pile);
void	ft_sa(t_node *lst);
void	ft_sb(t_node *lst);
void	ft_pa(t_node **pileA, t_node **pileB);
void	ft_pb(t_node **pileA, t_node **pileB);
void	ft_ra(t_node **pileA);
void	ft_rb(t_node **pileB);
void	ft_rra(t_node **pileA);
void	ft_rrb(t_node **pileB);
void	free_list(t_node *list);
t_node	*plus_petit_node(t_node *pileA);
void	sort(t_node **pileA, t_node **pileB);
int		ft_error_double(t_node *pileA);


