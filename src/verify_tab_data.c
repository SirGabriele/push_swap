/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_tab_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:04:07 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/19 01:14:42 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_tab_data(char **tab, t_ab *ab)
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
			ft_printf("Int [over/under]flow dectected\n");
			free(buf);
			clear_program(ab);
		}
		free(buf);
	}
}
