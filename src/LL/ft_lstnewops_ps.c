/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewops_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:09:28 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/05 18:10:27 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_ops_ps	*ft_lstnewops_ps(char *op, t_ab *ab)
{
	t_ops_ps	*elem;

	elem = malloc(sizeof(t_ops_ps));
	if (elem == NULL)
		clear_program(ab);
	elem->op = ft_strdup(op);
	elem->next = NULL;
	return (elem);
}
