/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:28:32 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/15 17:55:06 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_numbers(char *argv)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (argv[++i] != '\0')
	{
		if (argv[i] >= 48 && argv[i] <= 57)
		{
			count++;
			while (argv[i] != ' ' && argv[i] != '\0')
				i++;
			if (argv[i] == '\0')
				break ;
		}
	}
	return (count);
}
8
void	fill_tab(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i] != NULL)
	{
		count_numbers(argv[i]);
		ft_printf("%d\n", count_numbers(argv[i]));
	}
/*	while (argv[++i] != NULL)
	{
		if ()
	}*/
}
