/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:26:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/11 02:33:19 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc == 1)
		return (1);
	ab = malloc(sizeof(t_ab));
	init_program(ab);
	check_args(++argv, ab);
	fill_tab(argv, ab);
	indexing(ab);
	if (ab->size == 2 && ab->a->head->nbr > ab->a->head->next->nbr)
		sa(ab->a, ab);
	else if (ab->size <= 50 && ab->size > 2)
		sort_under_fifty_values(ab);
	else if (ab->size > 50)
		sort_with_radix(ab);
	optimize_ops(ab);
	print_ops(ab->ops);
	clear_program_good_ending(ab);
	return (0);
}
