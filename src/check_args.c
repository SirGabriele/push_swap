/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:16:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/15 17:03:43 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_charac_validity(char *argv)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	tab = "0123456789- ";
	while (argv[++i] != '\0')
	{
		j = -1;
		while (++j < 12)
		{
			if (argv[i] == tab[j])
				break ;
			if (j == 11)
			{
				ft_printf_error("Error\nInvalid character detected\n");
				clear_program();
			}
		}
	}
}

static void	check_minus_usage(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		if ((argv[i] == '-' && (argv[i + 1] < 48 || argv[i + 1] > 57))
			|| ((argv[i] >= 48 && argv[i] <= 57) && argv[i + 1] == '-'))

		{
			ft_printf_error("Error\nBad usage of minus sign\n");
			clear_program();
		}
	}
}

void	check_args(char **argv)
{
	int		i;

	i = -1;
	while (argv[++i] != NULL)
	{
		check_charac_validity(argv[i]);
		check_minus_usage(argv[i]);
	}
}	
