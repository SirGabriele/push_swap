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
		int		i = 0;
		int		j = 0;
		temp = ab->a->head;
		tempb = ab->b->head;
		i = 0;
		j = 0;
		
		ft_printf("\n\n---------------------------Avant---------------------------\n\n");
		while (temp != NULL || tempb)
		{
			if (temp)
			{
				ft_printf("A[%d] : %d\t", i++, temp->nbr);
				ft_printf("index : %d\t|\t", temp->index);
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
	

	
	sort_with_radix(ab);
	
	temp = ab->a->head;
	tempb = ab->b->head;
	i = 0;
	j = 0;
	temp = ab->a->head;
	tempb = ab->b->head;
	
	ft_printf("---------------------------Après---------------------------\n\n");
	while (temp || tempb)
	{
		if (temp)
		{		
//			ft_printf("%p\t", temp);
			ft_printf("A[%d] : %d\t", i++, temp->nbr);
//			ft_printf("%p\n", temp->next);
			ft_printf("index : %d", temp->index);
			temp = temp->next;
		}
		ft_printf("\n");
	}
//	ft_printf("%d\t", tempb->nbr);
//	ft_printf("\nab->magnitude : %d\n", ab->magnitude);
//	ft_printf("ab->size : %d\n", ab->size);

/*	temp = ab->a->head;
	tempb = ab->b->head;
	i = 0;
	j = 0;
	
	ft_printf("\n\n---------------------------Après---------------------------\n\n");
	while (temp != NULL || tempb)
	{
		if (temp)
		{
			ft_printf("A[%d] : %d\t", i++, temp->nbr);
			ft_printf("index : %d\t|\t", temp->index);
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
	
	temp = ab->a->head;
	tempb = ab->b->head;
	i = 0;
	j = 0;
	
	ft_printf("\n\n---------------------------Après x2---------------------------\n\n");
	while (temp != NULL || tempb)
	{
		if (temp)
		{
			ft_printf("A[%d] : %d\t", i++, temp->nbr);
			ft_printf("index : %d\t|\t", temp->index);
			temp = temp->next;
		}
		if (tempb)
		{
			ft_printf("B[%d] %d\t", j++, tempb->nbr);
			ft_printf("index : %d", tempb->index);
			tempb = tempb->next;
		}
		ft_printf("\n");
	}*/
	
	clear_program_good_ending(ab);
	return (0);
}
