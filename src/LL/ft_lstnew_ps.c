/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:27:24 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/18 22:29:29 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list_ps	*ft_lstnew_ps(int nbr, t_ab *ab)
{
	t_list_ps	*elem;

	elem = malloc(sizeof(t_list_ps));
	if (elem == NULL)
		clear_program(ab);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}
