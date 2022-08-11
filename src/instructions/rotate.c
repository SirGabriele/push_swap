/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:26:43 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 22:50:20 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack_ps *a, t_ab *ab)
{
	t_list_ps	*last;

	if (a->head == NULL)
		clear_program(ab);
	if (a->head->next == NULL)
		return ;
	last = a->head;
	while (last->next != NULL)
		last = last->next;
	last->next = a->head;
	a->head = a->head->next;
	last->next->next = NULL;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("ra", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("ra", ab));
}

void	rb(t_stack_ps *b, t_ab *ab)
{
	t_list_ps	*last;

	if (b->head == NULL)
		clear_program(ab);
	if (b->head->next == NULL)
		return ;
	last = b->head;
	while (last->next != NULL)
		last = last->next;
	last->next = b->head;
	b->head = b->head->next;
	last->next->next = NULL;
	if (ab->ops == NULL)
		ab->ops = ft_lstnewops_ps("rb", ab);
	else
		ft_lstadd_backops_ps(ab, ft_lstnewops_ps("rb", ab));
}

void	rr(t_ab *ab)
{
	ra(ab->a, ab);
	rb(ab->b, ab);
}
