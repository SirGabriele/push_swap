/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:16:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 22:49:50 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_ab *ab)
{
	t_list_ps	*copy;

	if (ab->b->head == NULL)
		ab->b->head = ft_lstnew_ps(ab->a->head->nbr, ab);
	copy = ab->a->head;
	ab->a->head = ab->b->head;
	ab->b->head = ab->b->head->next;
	ab->a->head->next = copy;
	write(1, "pa\n", 3);
}

void	pb(t_ab *ab)
{
	t_list_ps	*copy;

	if (ab->a->head == NULL)
		ab->a->head = ft_lstnew_ps(ab->b->head->nbr, ab);
	copy = ab->b->head;
	ab->b->head = ab->a->head;
	ab->a->head = ab->a->head->next;
	ab->b->head->next = copy;
	write(1, "pb\n", 3);
}
