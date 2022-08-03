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

void	ra(t_stack_ps *a)
{
	t_list_ps	*last;

	last = a->head;
	while (last->next != NULL)
		last = last->next;
	last->next = a->head;
	a->head = a->head->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack_ps *b)
{
	t_list_ps	*last;

	last = b->head;
	while (last->next != NULL)
		last = last->next;
	last->next = b->head;
	b->head = b->head->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_ab *ab)
{
	ra(ab->a);
	rb(ab->b);
}
