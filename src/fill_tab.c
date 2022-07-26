/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:28:32 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/20 16:08:53 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	verify_tab_data(char **tab, t_ab *ab)
{
	int		i;
	int		j;
	char	*buf;

	i = -1;
	while (tab[++i] != NULL)
	{
		j = ft_atoi(tab[i]);
		buf = ft_itoa(j);
		if (ft_strncmp(tab[i], buf, ft_strlen(tab[i])) != 0)
		{
			ft_printf_error("Int [over/under]flow dectected\n");// A SUPPRIMER
			free(buf);
			clear_program(ab);
		}
		free(buf);
	}
}

static void	is_duplicate(t_ab *ab)
{
	t_list_ps	*copy;
	t_list_ps	*checker;

	copy = ab->a->head;
	checker = NULL;
	while (copy->next != NULL)
	{
		checker = copy->next;
		while (checker != NULL)
		{
			if (copy->nbr == checker->nbr)
			{
				ft_printf_error("Duplicate values detected\n");// A SUPPRIMER
				clear_program(ab);
			}
			checker = checker->next;
		}
		copy = copy->next;
	}
}

static void	clear_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i] != NULL)
		free(tab[i]);
	free(tab);
}

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
	int			i;
	char		**tab;

	i = -1;
	while (argv[++i] != NULL)
	{
		if (count_numbers(argv[i]) == 1)
		{
			tab = ft_calloc(sizeof(char *), 2);
			if (tab == NULL)
			{
				ft_printf_error("Error while filling tab\n");//A SUPPRIMER
				clear_tab(tab);
				clear_program(ab);
			}
			tab[0] = ft_strdup(argv[i]);
		}
		else
			tab = ft_split(argv[i], ' ');
		verify_tab_data(tab, ab);
		fill_stack_a(tab, ab);
		clear_tab(tab);
	}
	is_duplicate(ab);
	calculate_magnitude(ab);
}
