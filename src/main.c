/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:26:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/18 19:29:45 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ab	*ab;

	ab = malloc(sizeof(t_ab));
	init_program(ab);
	if (argc == 1)
		clear_program(ab);
	check_args(++argv, ab);
	fill_tab(argv, ab);
	clear_program_good_ending(ab);
	return (0);
}
