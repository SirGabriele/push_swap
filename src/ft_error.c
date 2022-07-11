/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:33:43 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/05 16:19:39 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_args(int error)
{
	char error[10];

	error[0] = "";
	error[1] = "";
	error[2] = "";
	error[3] = "";
	error[4] = "";
	error[5] = "";
	error[6] = "";
	error[7] = "";
	error[8] = "";
	error[9] = "";
	ft_printf_error("Error\n");
	ft_printf_error("[ ARGS ERROR DETECTED ] : %s\n", error[1])
}
void	ft_error(int error)
{
	if (1 <= error && error <= 9)
		error_args(error);
	clear_pile();
}
