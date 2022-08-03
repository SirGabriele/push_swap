/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:21:59 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/03 10:40:03 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	transfer_all_b_in_a(t_ab *ab, t_list_ps **copya, t_list_ps **copyb)
{
	while (*copyb != NULL)
	{
		pa(ab);
		*copya = ab->a->head;
		*copyb = ab->b->head;
	}
}

static int	is_sorted(t_ab *ab)
{
	t_list_ps	*copy;

	copy = ab->a->head;
	while (copy->next != NULL)
	{
		if (copy->nbr > copy->next->nbr)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	sort_with_radix(t_ab *ab)
{
	t_list_ps	*copya;
	t_list_ps	*copyb;
	int			i;
	int			j;

	i = 0;
	copya = ab->a->head;
	copyb = ab->b->head;
	while (is_sorted(ab) == 0)
	{
		j = -1;
		while (++j < ab->size)
		{
			if (((copya->index >> i) & 1) == 0)
				pb(ab);
			else
				ra(ab->a);
			copya = ab->a->head;
		}
		copyb = ab->b->head;
		i++;
		transfer_all_b_in_a(ab, &copya, &copyb);
	}
}
