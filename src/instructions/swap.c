/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:11:19 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/20 18:26:47 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack_ps *a)
{
	int	temp;

	temp = a->head->nbr;
	a->head->nbr = a->head->next->nbr;
	a->head->next->nbr = temp;
}

void	sb(t_stack_ps *b)
{
	int	temp;

	temp = b->head->nbr;
	b->head->nbr = b->head->next->nbr;
	b->head->next->nbr = temp;
}

void	ss(t_stack_ps *a, t_stack_ps *b)
{
	sa(a);
	sb(b);
}
