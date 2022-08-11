/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:54:44 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 01:19:15 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	delete_first_second(t_ops_ps *first, t_ops_ps *second)
{
	free(first->op);
	first->op = NULL;
	free(first);
	first = NULL;
	free(second->op);
	second->op = NULL;
	free(second);
	second = NULL;
}

static t_ops_ps	*delete_links(t_ops_ps *first, t_ops_ps *second, t_ab *ab)
{
	t_ops_ps	*before;
	t_ops_ps	*after;

	before = ab->ops;
	while (before != NULL && before != first && before->next != first)
		before = before->next;
	after = second->next;
	if (first == ab->ops)
	{
		ab->ops = after;
		delete_first_second(first, second);
		return (after);
	}
	else
	{
		before->next = after;
		delete_first_second(first, second);
		return (before);
	}
}

static t_ops_ps	*cancelling_ops(t_ops_ps *first, t_ops_ps *second, t_ab *ab)
{
	if ((ft_strncmp(first->op, "ra", 2) == 0
			&& ft_strncmp(second->op, "rra", 3) == 0)
		|| (ft_strncmp(first->op, "rb", 2) == 0
			&& ft_strncmp(second->op, "rrb", 3) == 0))
		return (delete_links(first, second, ab));
	else if ((ft_strncmp(first->op, "rra", 3) == 0
			&& ft_strncmp(second->op, "ra", 2) == 0)
		|| (ft_strncmp(first->op, "rrb", 3) == 0
			&& ft_strncmp(second->op, "rb", 2) == 0))
		return (delete_links(first, second, ab));
	else if ((ft_strncmp(first->op, "pa", 2) == 0
			&& ft_strncmp(second->op, "pb", 2) == 0)
		|| (ft_strncmp(first->op, "pb", 2) == 0
			&& ft_strncmp(second->op, "pa", 2) == 0))
		return (delete_links(first, second, ab));
	else if ((ft_strncmp(first->op, "sa", 2) == 0
			&& ft_strncmp(second->op, "sa", 2) == 0)
		|| (ft_strncmp(first->op, "sb", 2) == 0
			&& ft_strncmp(second->op, "sb", 2) == 0))
		return (delete_links(first, second, ab));
	else
		return (second);
}

void	optimize_ops(t_ab *ab)

{
	t_ops_ps	*copy;

	copy = ab->ops;
	while (copy != NULL && copy->next != NULL)
		copy = cancelling_ops(copy, copy->next, ab);
}
