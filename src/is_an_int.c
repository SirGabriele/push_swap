/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_an_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:05:13 by kbrousse          #+#    #+#             */
/*   Updated: 2022/08/03 10:35:18 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_an_int(char *tab)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (((tab[i] >= 9 && tab[i] <= 13) || tab[i] == 32) && tab[i] != '\0')
			i++;
	if (tab[i] == '\0')
		return (1);
	if (tab[i++] == 45)
		sign = -sign;
	while (tab[i] >= 48 && tab[i] <= 57)
	{
		res = res * 10 + (tab[i] - 48);
		i++;
		if ((sign == 1 && res > 2147483647) || (sign == -1 && res > 2147483648))
			return (1);
	}
	return (0);
}
