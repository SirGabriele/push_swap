/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:26:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 23:48:32 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc == 2)
		return (1);
	ab = malloc(sizeof(t_ab));
	init_program(ab);
	check_args(++argv, ab);
	fill_tab(argv, ab);
	
	
	t_list_ps	*temp;
	temp = ab->a->head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}
	ft_printf("\n\nMagnitude : %d\n", ab->magnitude);
	/*sa(ab->a);
	
	temp = ab->a->head;
	while (temp != NULL)
	{
		ft_printf("%d\n", temp->nbr);
		temp = temp->next;
	}*/
	clear_program_good_ending(ab);
	return (0);
}
