/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:11:19 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/20 18:26:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack_ps *a, t_ab *ab)
{
	int	temp;

	if (a->head == NULL)
		clear_program(ab);
	if (a->head->next == NULL)
		return ;
	temp = a->head->nbr;
	a->head->nbr = a->head->next->nbr;
	a->head->next->nbr = temp;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("sa", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("sa", ab));
}

void	sb(t_stack_ps *b, t_ab *ab)
{
	int	temp;

	if (b->head == NULL)
		clear_program(ab);
	if (b->head->next == NULL)
		return ;
	temp = b->head->nbr;
	b->head->nbr = b->head->next->nbr;
	b->head->next->nbr = temp;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("sb", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("sb", ab));
}

void	ss(t_ab *ab)
{
	sa(ab->a, ab);
	sb(ab->b, ab);
}
