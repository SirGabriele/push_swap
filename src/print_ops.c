/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:45:06 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 11:56:41 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(t_ops_ps *ops)
{
	t_ops_ps	*copy;

	copy = ops;
	while (copy != NULL)
	{
		ft_printf("%s\n", copy->op);
		copy = copy->next;
	}
}
