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

void	rra(t_stack_ps *a)
{
	t_list_ps	*last;
	t_list_ps	*copy;
	t_list_ps	*penultimate;

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
	write(1, "rra", 3);
}

void	rrb(t_stack_ps *b)
{
	t_list_ps	*last;
	t_list_ps	*copy;
	t_list_ps	*penultimate;

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
	write(1, "rrb", 3);
}

void	rrr(t_stack_ps *a, t_stack_ps *b)
{
	rra(a);
	rrb(b);
}
