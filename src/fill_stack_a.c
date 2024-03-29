/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:33:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/19 07:30:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack_a(char **tab, t_ab *ab)
{
	int			i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_lstadd_back_ps(ab->a, ft_lstnew_ps(ft_atoi(tab[i]), ab));
		i++;
	}
}
