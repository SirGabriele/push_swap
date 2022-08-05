/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:26:41 by kbrousse          #+#    #+#             */
/*   Updated: 2022/07/26 23:48:32 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ab	*ab;

	if (argc == 1)
		return (1);
	ab = malloc(sizeof(t_ab));
	init_program(ab);
	check_args(++argv, ab);
	fill_tab(argv, ab);
	indexing(ab);
	

	t_list_ps	*temp;
	t_list_ps	*tempb;
	t_ops_ps	*tempc;
	
	int		i = 0;
	int		j = 0;
	int		k = 0;
	temp = ab->a->head;
	tempb = ab->b->head;
		
		ft_printf("\n\n--------------Unsorted--------------\n\n");
		while (temp || tempb)
		{
			if (temp)
			{
				ft_printf("A[%d] : %d\t\t", i++, temp->nbr);
				ft_printf("index : %d", temp->index);
				temp = temp->next;
			}
			if (tempb)
			{
				ft_printf("B[%d] %d\t", j++, tempb->nbr);
				ft_printf("index : %d", tempb->index);
				tempb = tempb->next;
			}
			ft_printf("\n");
		}
	ft_printf("\n");
	
	if (ab->size == 2 && ab->a->head->nbr > ab->a->head->next->nbr)
		sa(ab->a);
	else if (ab->size <= 50 && ab->size > 2)
		sort_under_fifty_values(ab);
	else if (ab->size >= 100)
		sort_with_radix(ab);
	
	temp = ab->a->head;
	tempb = ab->b->head;
	tempc = ab->ops;
	i = 0;
	j = 0;
	k = 0;

	ft_printf("---------------Sorted---------------\n\n");
	while (temp || tempb)
	{
		if (temp)
		{		
			ft_printf("A[%d] : %d\t", i++, temp->nbr);
			ft_printf("index : %d\t", temp->index);
			temp = temp->next;
		}
		if (tempb)
		{			
			ft_printf("|\tB[%d] : %d\t", j++, tempb->nbr);
			ft_printf("index : %d\t", tempb->index);
			tempb = tempb->next;
		}
		ft_printf("\n");
	}
	
	ft_printf("\n\n");
	while (tempc)
	{
		if (tempc)
		{
			ft_printf("OP[%d] : %s\n", k++, tempc->op);
			tempc = tempc->next;
		}
	}
	
	clear_program_good_ending(ab);
	return (0);
}
