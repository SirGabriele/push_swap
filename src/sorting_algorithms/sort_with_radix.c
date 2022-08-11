/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:21:59 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 11:57:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_size_of_list(t_list_ps *list)
{
	int			i;
	t_list_ps	*copy;

	i = 0;
	copy = list;
	while (copy != NULL)
	{
		i++;
		copy = copy->next;
	}
	return (i);
}

static void	transfer_some_b_in_a(t_ab *ab, int i)
{
	int	size;
	int	j;

	j = -1;
	size = ft_size_of_list(ab->b->head);
	while (++j < size)
	{
		if (((ab->b->head->index >> i) & 1) == 1)
			pa(ab);
		else
			rb(ab->b, ab);
	}
}

static void	transfer_all_b_in_a(t_ab *ab)
{
	while (ab->b->head != NULL)
		pa(ab);
}

int	is_sorted(t_ab *ab)
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
	int			i;
	int			j;
	int			size;

	i = 0;
	while (is_sorted(ab) == 0)
	{
		j = -1;
		size = ft_size_of_list(ab->a->head);
		while (++j < size)
		{
			if (((ab->a->head->index >> i) & 1) == 0)
				pb(ab);
			else
				ra(ab->a, ab);
		}
		i++;
		if (is_sorted(ab) == 0)
			transfer_some_b_in_a(ab, i);
	}
	transfer_all_b_in_a(ab);
}
