/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:59:34 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 22:50:39 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack_ps *a, t_ab *ab)
{
	t_list_ps	*last;
	t_list_ps	*copy;
	t_list_ps	*penultimate;

	if (a->head == NULL)
		clear_program(ab);
	if (a->head->next == NULL)
		return ;
	copy = a->head;
	last = a->head;
	penultimate = NULL;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	a->head = last;
	last->next = copy;
	penultimate->next = NULL;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("rra", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("rra", ab));
}

void	rrb(t_stack_ps *b, t_ab *ab)
{
	t_list_ps	*last;
	t_list_ps	*copy;
	t_list_ps	*penultimate;

	if (b->head == NULL)
		clear_program(ab);
	if (b->head->next == NULL)
		return ;
	copy = b->head;
	last = b->head;
	penultimate = NULL;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	b->head = last;
	last->next = copy;
	penultimate->next = NULL;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("rrb", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("rrb", ab));
}

void	rrr(t_ab *ab)
{
	rra(ab->a, ab);
	rrb(ab->b, ab);
}
