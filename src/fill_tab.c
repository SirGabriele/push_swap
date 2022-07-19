/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:28:32 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/18 20:35:51 by kbrousse         ###   ########.fr       */
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

void	fill_tab(char **argv, t_ab *ab)
{
	int		i;
	int		j;
	char	**tab;

	i = -1;
	while (argv[++i] != NULL)
	{
		if (count_numbers(argv[i]) == 1)
		{
			tab = ft_calloc(sizeof(char *), 2);
			if (tab == NULL)
			{
				ft_printf("Error while filling tab\n");//A SUPPRIMER
				clear_program(ab);
			}
			tab[0] = ft_strdup(argv[i]);
		}
		else
			tab = ft_split(argv[i], ' ');
		verify_tab_data(tab, ab);
		fill_stack_a(tab, ab);
		j = -1;
		while (tab[++j] != NULL)
			free(tab[j]);
		free(tab);
	}
}
