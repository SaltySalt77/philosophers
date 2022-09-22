/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 12:17:02 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int free_and_exit(t_philo_lst	*philo)
{
	t_philo_lst	*head;
	t_philo_lst	*tmp;
	t_info		*info;
	int 		i;

	i = 0;
	head = philo->head;
	while (i <= info->p_args[NBR_OF_PHILO])
	{
		pthread_mutex_unlock(&(info->forks[i]));
		pthread_mutex_destroy(&(info->forks[i]));
	}
	free(info->forks);
	free(info->p_args);
	free(info->p_ids);
	while (head)
	{
		tmp = head;
		free(head->last_meal_time);
		head = head->next;
		free(tmp);	
	}
	exit(0);
}
