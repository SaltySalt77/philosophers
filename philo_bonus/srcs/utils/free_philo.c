/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 19:29:31 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_info	*info)
{
	int	i;

	i = 1;
	while (i <= info->p_args[NBR_OF_PHILO])
		pthread_mutex_destroy(&(info->forks[i++]));
	i = 1;
	while (i <= info->p_args[NBR_OF_PHILO])
		pthread_mutex_destroy(&(info->meal[i++]));
	pthread_mutex_destroy(&(info->print));
	pthread_mutex_destroy(&(info->start));
	pthread_mutex_destroy(&(info->status));
}

int	free_philo(t_philo_lst	*philo)
{
	t_philo_lst		*head;
	t_philo_lst		*tmp;
	t_info			*info;

	head = philo->head;
	info = philo->info;
	destroy_mutexes(info);
	free(info->std_time);
	free_info(info);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->last_meal_time);
		memset(tmp, 0, sizeof(t_philo_lst));
		free(tmp);
	}
	return (1);
}
