/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:16:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/20 16:39:40 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_plus_usage(char *argv, t_ab *ab)
{
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		if ((argv[i] == '+' && (argv[i + 1] < 48 || argv[i + 1] > 57))
			|| ((argv[i] >= 48 && argv[i] <= 57) && (argv[i + 1] == '+')))
			clear_program(ab);
	}
}

static void	check_minus_usage(char *argv, t_ab *ab)
{
	int	i;

	i = -1;
	while (argv[++i] != '\0')
	{
		if ((argv[i] == '-' && (argv[i + 1] < 48 || argv[i + 1] > 57))
			|| ((argv[i] >= 48 && argv[i] <= 57) && (argv[i + 1] == '-')))
			clear_program(ab);
	}
}

static void	check_charac_validity(char *argv, t_ab *ab)
{
	char	*tab;
	int		i;
	int		j;

	i = -1;
	tab = "0123456789-+ ";
	while (argv[++i] != '\0')
	{
		j = -1;
		while (++j < 13)
		{
			if (argv[i] == tab[j])
				break ;
			if (j == 12)
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
		if (argv[i][0] == '\0')
			clear_program(ab);
		check_charac_validity(argv[i], ab);
		check_minus_usage(argv[i], ab);
		check_plus_usage(argv[i], ab);
	}
	ab->a = malloc(sizeof(t_stack_ps));
	ab->b = malloc(sizeof(t_stack_ps));
	if (ab->a == NULL || ab->b == NULL)
		clear_program(ab);
	init_stack_a(ab->a);
	init_stack_b(ab->b);
}	
