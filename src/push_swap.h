/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:15:16 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/05 18:05:16 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ops_ps
{
	char			*op;
	struct s_ops_ps	*next;
}	t_ops_ps;

typedef struct s_list_ps
{
	int					nbr;
	int					index;
	struct s_list_ps	*next;
}	t_list_ps;

typedef struct s_stack_ps
{
	struct s_list_ps	*head;
}	t_stack_ps;

typedef struct s_ab
{
	struct s_stack_ps	*a;
	struct s_stack_ps	*b;
	struct s_ops_ps	*ops;
	int					size;
}	t_ab;

void		check_args(char **argv, t_ab *ab);
void		fill_tab(char **argv, t_ab *ab);
int			is_an_int(char *tab);
void		fill_stack_a(char **tab, t_ab *ab);
void		clear_program(t_ab *ab);
void		clear_program_good_ending(t_ab *ab);

// Init functions
void		init_program(t_ab *ab);
void		init_stack_a(t_stack_ps *a);
void		init_stack_b(t_stack_ps *b);

// Sorting functions
void		indexing(t_ab *ab);
void		sort_under_fifty_values(t_ab *ab);
void		sort_with_radix(t_ab *ab);

// LL functions
t_list_ps	*ft_lstnew_ps(int nbr, t_ab *ab);
t_ops_ps	*ft_lstnewops_ps(char *op, t_ab *ab);
void		ft_lstadd_front_ps(t_stack_ps *a, t_list_ps *new);
void		ft_lstadd_back_ps(t_stack_ps *a, t_list_ps *new);
void		ft_lstadd_backops_ps(t_ab *ab, t_ops_ps *new);

// Instructions
void		sa(t_stack_ps *a);
void		sb(t_stack_ps *b);
void		ss(t_ab *ab);
void		pa(t_ab *ab);
void		pb(t_ab *ab);
void		ra(t_stack_ps *a);
void		rb(t_stack_ps *b);
void		rr(t_ab *ab);
void		rra(t_stack_ps *a);
void		rrb(t_stack_ps *b);
void		rrr(t_ab *ab);

#endif
