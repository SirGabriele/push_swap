/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_fifty_values.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:47:50 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/03 15:09:36 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	transfer_all_b_in_a(t_ab *ab)
{
	t_list_ps	*copya;
	t_list_ps	*copyb;

	copya = ab->a->head;
	copyb = ab->b->head;
	while (copyb != NULL)
	{
		pa(ab);
		copya = ab->a->head;
		copyb = ab->b->head;
	}
	copya++;
}

static void	push_biggest_value(t_ab *ab)
{
	t_list_ps	*copy;
	int			min_nbr;
	int			i;

	i = 0;
	copy = ab->a->head->next;
	min_nbr = ab->a->head->nbr;
	while (copy != NULL)
	{
		if (copy->nbr < min_nbr)
		{
			min_nbr = copy->nbr;
			i++;;
		}
		copy = copy->next;
	}
	while (ab->a->head->nbr != min_nbr)
	{
		if (i <= ab->size / 2)
			ra(ab->a);
		else
			rra(ab->a);
	}
	pb(ab);
}

static void	sort_three_values(t_ab *ab)
{
	t_list_ps	*c;

	indexing(ab);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1) ||
		(c->index == 2 && c->next->index == 0 && c->next->next->index == 1))
		ra(ab->a);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1)
		|| (c->index == 1 && c->next->index == 0 && c->next->next->index == 2)
		|| (c->index == 2 && c->next->index == 1 && c->next->next->index == 0))
		sa(ab->a);
	c = ab->a->head;
	if ((c->index == 0 && c->next->index == 2 && c->next->next->index == 1)
		|| (c->index == 1 && c->next->index == 2 && c->next->next->index == 0)
		|| (c->index == 2 && c->next->index == 1 && c->next->next->index == 0))
		rra(ab->a);
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
		push_biggest_value(ab);
		sort_under_fifty_values(ab);
	}
	transfer_all_b_in_a(ab);
}
