/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:21:59 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/30 13:54:25 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_with_radix(t_ab *ab)
{
	t_list_ps	*copy;
	t_list_ps	*copyb;
	int	i;
	int	j;

	i = 1;
	j = -1;
	copy = ab->a->head;
	copyb = ab->b->head;
	while (i <= ab->magnitude)
	{
		while (++j < ab->size)
		{
			if (copy->index >> i == 1)
			{
				pa(ab->a, ab->b);
			}
			else
				ra(ab->a);
		}
		i++;
		while (copyb != NULL)
			pb(ab->a, ab->b);
	}
}
