/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_fifty_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:47:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 01:42:08 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_smallest_value(t_ab *ab)
{
	t_list_ps	*copy;
	int			min_nbr;
	int			i;
	int			j;
	
	i = 0;
	j = 0;	
	copy = ab->a->head->next;
	min_nbr = ab->a->head->nbr;
	while (copy != NULL)
	{
		if (copy->nbr < min_nbr)
		{
			min_nbr = copy->nbr;
			j = i;
		}
		i++;
		copy = copy->next;
	}
	while (ab->a->head->nbr != min_nbr)
	{
		if (j < ft_size_of_list(ab->a->head) / 2)
			ra(ab->a, ab);
		else
			rra(ab->a, ab);
	}
	pb(ab);
}

static void	sort_three_values(t_ab *ab)
{
	t_list_ps	*c;

	indexing(ab);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1)
		|| (c->index == 2 && c->next->index == 0 && c->next->next->index == 1))
		ra(ab->a, ab);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1)
		|| (c->index == 1 && c->next->index == 0 && c->next->next->index == 2)
		|| (c->index == 2 && c->next->index == 1 && c->next->next->index == 0))
		sa(ab->a, ab);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1)
		|| (c->index == 1 && c->next->index == 2 && c->next->next->index == 0)
		|| (c->index == 2 && c->next->index == 1 && c->next->next->index == 0))
		rra(ab->a, ab);
}

static int	ft_lstsize_ps(t_ab *ab)
{
	t_list_ps	*copy;
	int			i;

	i = 0;
	copy = ab->a->head;
	while (copy != NULL)
	{
		copy = copy->next;
		i++;
	}
	return (i);
}

void	sort_under_fifty_values(t_ab *ab)
{
	if (ft_lstsize_ps(ab) == 3)
		sort_three_values(ab);
	else
	{
		push_smallest_value(ab);
		sort_under_fifty_values(ab);
	}
	transfer_all_b_in_a(ab);
}
