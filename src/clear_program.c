/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:35:26 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/18 21:51:12 by kbrousse         ###   ########.fr       */
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
	free(stack->head);
}

void	clear_program(t_ab *ab)
{
	if (ab->a != NULL)
		clear_stack(ab->a);
	if (ab->b != NULL)
		clear_stack(ab->b);
	free(ab->a);
	free(ab->b);
	free(ab);
	ab = NULL;
	ft_printf("Error\n");
	exit(0);
}
