/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eaten_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:54 by hyna              #+#    #+#             */
/*   Updated: 2022/09/25 14:32:23 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_min_time(t_philo_lst	*philo)
{
	t_philo_lst		*curr;
	int				min_time;

	curr = philo;
	min_time = philo->info->p_args[MUST_EAT];
	while (curr)
	{
		pthread_mutex_lock(&(philo->info->status));
		if (curr->eaten_time < min_time)
			min_time = curr->eaten_time;
		pthread_mutex_unlock(&(philo->info->status));
		curr = curr->next;
	}
	return (min_time);
}

static int	set_status(t_philo_lst	*philo)
{
	int				min_time;

	min_time = get_min_time(philo);
	pthread_mutex_lock(&(philo->info->status));
	if (min_time == philo->info->p_args[MUST_EAT])
	{
		pthread_mutex_unlock(&(philo->info->status));
		return (1);
	}
	if (philo->info->flag != NOTHING)
	{
		pthread_mutex_unlock(&(philo->info->status));
		return (1);
	}
	pthread_mutex_unlock(&(philo->info->status));
	return (0);
}

void	*check_eaten_time(void	*value)
{
	t_philo_lst		*philo;

	philo = (t_philo_lst *) value;
	wait_stdtime(philo->info);
	while (1)
	{
		if (set_status(philo))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&(philo->info->status));
	philo->info->flag = EATEN_ALL;
	pthread_mutex_unlock(&(philo->info->status));
	return (0);
}
