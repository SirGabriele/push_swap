/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:16:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 22:49:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack_ps *a, t_stack_ps *b)
{
	t_list_ps	*copy;

	if (b->head == NULL)
		return ;
	copy = a->head;
	a->head = b->head;
	b->head = b->head->next;
	a->head->next = copy;
	write(1, "pa", 2);
}

void	pb(t_stack_ps *a, t_stack_ps *b)
{
	t_list_ps	*copy;

	copy = b->head;
	b->head = a->head;
	a->head = a->head->next;
	b->head->next = copy;
	write(1, "pb", 2);
}
