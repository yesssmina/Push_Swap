/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:06:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 20:12:41 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include "./Libft/libft.h"


typedef struct		s_node
{
	struct s_node	*prev;
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
int		size_pileA(t_node *pileA);
int		smallest_place(t_node *pileA, t_node *smallest);
void	mediane_rb(t_node **pileB, t_node *biggest);
void	mediane_rrb(t_node **pileB, t_node *biggest);
void	divide_and_push(t_node **pileA, t_node **pileB, int segment_size);
int		max_segment(int size_pile, int nb_segment);
void	sort_push_a(t_node **pileA, t_node **pileB);
t_node	*plus_grand_node(t_node *pileB);
int		biggest_place(t_node *pileB, t_node *biggest);
void	sort_push_b(t_node **pileA, t_node **pileB, int smallest, int seg_until);
void	best_b_place(t_node **pileA, t_node **pileB);
void	nb_arg(t_node **pileA, t_node **pileB, int	ac);