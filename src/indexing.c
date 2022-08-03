/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:58:14 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/03 10:34:46 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_ab *ab)
{
	t_list_ps	*copy;
	t_list_ps	*reader;
	int			hm_inf;

	copy = ab->a->head;
	hm_inf = 0;
	while (copy != NULL)
	{
		reader = ab->a->head;
		while (reader != NULL)
		{
			if (reader->nbr < copy->nbr)
				hm_inf++;
			reader = reader->next;
		}
		copy->index = hm_inf;
		copy = copy->next;
		hm_inf = 0;
	}
}
