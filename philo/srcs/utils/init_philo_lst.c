/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:02:35 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 19:26:35 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo_lst	*add_new_node(t_info *info, int p_nbr)
{
	t_philo_lst	*node;

	node = malloc(sizeof(t_philo_lst));
	check_alloc(node);
	node->name = p_nbr;
	node->left_fork = p_nbr - 1;
	node->right_fork = p_nbr;
	if (node->left_fork == 0)
		node->left_fork = info->p_args[NBR_OF_PHILO];
	node->last_meal_time = 0;
	node->info = info;
	node->next = NULL;
	return (node);
}

t_philo_lst	*init_philo_lst(t_info	*info)
{
	t_philo_lst		*head;
	t_philo_lst		*curr;
	int				p_nbr;

	p_nbr = 1;
	head = add_new_node(info, p_nbr);
	p_nbr++;
	curr = head;
	while (p_nbr <= info->p_args[NBR_OF_PHILO])
	{
		curr->next = add_new_node(info, p_nbr++);
		curr = curr->next;
	}
	return (head);
}
