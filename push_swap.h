/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 00:06:20 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 03:33:36 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct	push
{
	t_node  *pile;
	int     valeur;
	int     i;
	int		j;
	char	**res;
	t_node **pileA;
	t_node **pileB;
	t_node	*tmp;
	int		top_node;
	int		value;
	int		all_smaller;
	t_node	*top_n;
	t_node	*bottom_node;
	int		smallest;
	int		count_top;
	int		count_bottom;
	int		size;
	int		until;
	int		memo_until;
	int		ac1;

	
}				t_push;


void	add_back(t_node **begin, int value);
void	add_front(t_node **begin, int value);
t_node  *ft_create_pileA(t_push *push, int ac, char **av);
void	ft_print_pile(t_node *pile);
void	ft_sa(t_node **lst);
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
void	divide_and_push(t_push *push, int	nb_segment);
int		max_segment(int size_pile, int nb_segment);
void	sort_push_a(t_node **pileA, t_node **pileB);
t_node	*plus_grand_node(t_node *pileB);
int		biggest_place(t_node *pileB, t_node *biggest);
void	sort_push_b(t_push *push);
void	nb_arg(t_push *push);
void	ft_init(t_push *push);
void	ft_init1(t_push *push);
void	ft_init2(t_push *push, int nb_seg);
void	ft_init3(t_push *push);
void	begin_sort_push_b(t_push *push);
char	*error_mess(char *message);
int		ft_no_digit(char *str);
void	sorted(t_push *push);
void	if_biggest(t_node **pileA, int smallest);
int		three_items(t_node **pileA);
int		four_items(t_node **pileA, t_node **pileB);
int		five_items(t_node **pileA, t_node **pileB);
t_node	*second_plus_petit_node(t_node *pileA, int smallest);
int		gia_sorted(t_node **pileA);
void ft_init_create(t_push *push, char **av);
#endif