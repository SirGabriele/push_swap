/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backops_ps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:13:47 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/05 18:14:26 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_backops_ps(t_ab *ab, t_ops_ps *new)
{
	t_ops_ps	*copy;

	copy = ab->ops;
	if (ab->ops == NULL)
		ab->ops = new;
	else
	{
		while (copy->next != NULL)
			copy = copy->next;
		copy->next = new;
	}
}
