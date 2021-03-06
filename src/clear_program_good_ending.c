/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_program_good_ending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:26 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/19 00:08:57 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_list(t_list_ps *list)
{
	t_list_ps	*copy;

	copy = list;
	while (copy != NULL)
	{
		copy = list->next;
		free(list);
		list = copy;
	}
	list = NULL;
}

static void	clear_stack(t_stack_ps *stack)
{
	if (stack->head != NULL)
		clear_list(stack->head);
}

void	clear_program_good_ending(t_ab *ab)
{
	if (ab->a != NULL)
		clear_stack(ab->a);
	if (ab->b != NULL)
		clear_stack(ab->b);
	free(ab);
	ab = NULL;
	exit(0);
}
