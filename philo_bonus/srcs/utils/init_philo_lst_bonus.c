/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:02:35 by hyna              #+#    #+#             */
/*   Updated: 2022/09/28 23:46:34 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_philo_lst	*add_new_node(t_info *info, int p_nbr, t_philo_lst	*head)
{
	t_philo_lst	*node;

	node = malloc(sizeof(t_philo_lst));
	if (node == NULL)
		return (NULL);
	node->name = p_nbr;
	node->eaten_time = 0;
	node->last_act = 0;
	node->last_meal_time = NULL;
	node->info = info;
	node->head = head;
	node->next = NULL;
	if (node->name == info->p_args[NBR_OF_PHILO])
		cross_hands(node);
	return (node);
}

static void	*free_philo_lst(t_philo_lst	*philo)
{
	t_philo_lst	*tmp;

	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
	return (NULL);
}

t_philo_lst	*init_philo_lst(t_info	*info)
{
	t_philo_lst		*head;
	t_philo_lst		*curr;
	int				p_nbr;

	p_nbr = 1;
	head = add_new_node(info, p_nbr, NULL);
	head->head = head;
	p_nbr++;
	curr = head;
	while (p_nbr <= info->p_args[NBR_OF_PHILO])
	{
		curr->next = add_new_node(info, p_nbr++, head);
		if (curr->next == NULL)
			return (free_philo_lst(head));
		curr = curr->next;
	}
	return (head);
}
