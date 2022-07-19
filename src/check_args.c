/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:16:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/18 17:08:22 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_charac_validity(char *argv, t_ab *ab)
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
				ft_printf("Forbidden symbol detected\n");
				clear_program(ab);
			}
		}
	}
}

static void	check_minus_usage(char *argv, t_ab *ab)
{
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		if ((argv[i] == '-' && (argv[i + 1] < 48 || argv[i + 1] > 57))
			|| ((argv[i] >= 48 && argv[i] <= 57) && argv[i + 1] == '-'))
		{
			ft_printf("Bad usage of - sign\n");
			clear_program(ab);
		}
	}
}

void	check_args(char **argv, t_ab *ab)
{
	int		i;

	i = -1;
	while (argv[++i] != NULL)
	{
		check_charac_validity(argv[i], ab);
		check_minus_usage(argv[i], ab);
	}
}	
