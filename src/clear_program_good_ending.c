/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_program_good_ending.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:26 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 01:43:08 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_ops(t_ops_ps *ops)
{
	t_ops_ps	*copy;

	copy = ops;
	while (copy != NULL)
	{
		copy = ops->next;
		if (ops->op != NULL)
		{
			free(ops->op);
			ops->op = NULL;
		}
		free(ops);
		ops = copy;
	}
	ops = NULL;
}

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
	if (ab->ops != NULL)
		clear_ops(ab->ops);
	free(ab->a);
	ab->a = NULL;
	free(ab->b);
	ab->b = NULL;
	free(ab);
	ab = NULL;
	exit(0);
}
