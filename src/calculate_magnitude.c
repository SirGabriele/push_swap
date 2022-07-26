/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_magnitude.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:04:07 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 23:54:35 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_magnitude(int max_value, t_ab *ab)
{
	int	count;

	count = 0;
	while (max_value != 0)
	{
		max_value = max_value >> 1;
		count++;
	}
	ab->magnitude = count;
}

void	calculate_magnitude(t_ab *ab)
{
	int			max_value;
	t_list_ps	*copy;
	int			temp;
	
	copy = ab->a->head;
	max_value = 0;
	temp = 0;
	while (copy != NULL)
	{
		if (copy->nbr < 0)
			temp = -copy->nbr;
		if (temp > max_value)
			max_value = temp;
		if (copy->nbr > max_value)
			max_value = copy->nbr;
		copy = copy->next;
	}
	find_magnitude(max_value, ab);
}
