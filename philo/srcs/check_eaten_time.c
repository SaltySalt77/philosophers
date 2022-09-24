/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eaten_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:54 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 17:50:30 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_eaten_time(void	*value)
{
	t_philo_lst		*philo;
	t_philo_lst		*curr;
	int				min_time;

	philo = (t_philo_lst *) value;
	wait_stdtime(philo->info);
	while (1)
	{
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
		pthread_mutex_lock(&(philo->info->status));
		if (min_time == philo->info->p_args[MUST_EAT])
		{
			pthread_mutex_unlock(&(philo->info->status));
			break ;
		}
		if (philo->info->flag != NOTHING)
		{
			pthread_mutex_unlock(&(philo->info->status));
			break ;
		}
		pthread_mutex_unlock(&(philo->info->status));
		usleep(100);
	}
	pthread_mutex_lock(&(philo->info->status));
	philo->info->flag = EATEN_ALL;
	pthread_mutex_unlock(&(philo->info->status));
	return (0);
}
