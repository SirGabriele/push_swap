/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:33:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/19 02:06:14 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(char **tab, t_ab *ab)
{
	int			i;

	i = 0;
	ab->a = malloc(sizeof(t_stack_ps));
	if (ab->a == NULL)
		clear_program(ab);
	init_stack_a(ab->a);
	if (ab->a->head == NULL)
	{
		ab->a->head = ft_lstnew_ps(ft_atoi(tab[i]), ab);
		i++;
	}
	ft_printf("%d\n")
	while (tab[i] != NULL)
	{
		ft_lstadd_front_ps(ab->a->head, ft_lstnew_ps(ft_atoi(tab[i]), ab));
		i++;
	}
}
