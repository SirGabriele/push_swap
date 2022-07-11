/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 15:16:20 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/11 23:18:48 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_string(char *str)
{
	int	i;

	i = -1;
	while(str[++i] != '\0')
	{
		if (str[i] == ' ')
			return (1);
	}
	return (0);
}

static int	is_valid(char *str)
{
	int	i;
	
	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] != ' ')
		{
			ft_printf_error("Only digits characters are allowed as arguments");
//			clear_program();
			return (0);
		}
		if (str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		{
			ft_printf_error("Space is the only splitting character allowed \
				in strings");
//			clear_program();
			return (0);
		}
	}
	return (1);
}

static int	count_numbers(char	*str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			count++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
			if (str[i] == '\0')
				break ;
		}
	}
	return (count);
}

void	check_args(char **argv)
{
	int		i;
	char	**tab;
	int		pr;

	i = -1;
	pr = -1;
	while (argv[++i] != NULL)
	{
		tab = ft_calloc(sizeof(char *), count_numbers(argv[i]) + 1);
		if (is_string(argv[i]) == 1 && is_valid(argv[i]) == 1)
//			check validity and split all the arguments;
			tab = ft_split(argv[i], ' ');
		else if (is_string(argv[i]) == 0 && is_valid(argv[i]) == 1)
			tab[i] = argv[i];
		ft_printf("count_numbers = %d\n", count_numbers(argv[i]));
		while (tab[++pr] != NULL)
			ft_printf("%s\n", tab[pr]);
//		convert tab into link;
		free(tab);
		tab = NULL;
	}
}
