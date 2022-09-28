/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:18:20 by hyna              #+#    #+#             */
/*   Updated: 2022/09/28 21:52:54 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	is_dead(t_philo_lst	*philo)
{
	struct timeval	curr;

	gettimeofday(&curr, NULL);
	pthread_mutex_lock(&(philo->info->meal[philo->name]));
	if (philo->last_meal_time && get_timestamp(philo->last_meal_time, &curr)
		>= philo->info->p_args[TIME_TO_DIE])
		print_status(philo, DEAD_MSG);
	else if (!(philo->last_meal_time)
		&& get_timestamp(philo->info->std_time, &curr)
		>= philo->info->p_args[TIME_TO_DIE])
		print_status(philo, DEAD_MSG);
	pthread_mutex_unlock(&(philo->info->meal[philo->name]));
}

void	*check_death(void	*value)
{
	t_philo_lst		*philo;

	philo = (t_philo_lst *) value;
	wait_stdtime(philo->info);
	while (1)
	{
		is_dead(philo);
		pthread_mutex_lock(&(philo->info->status));
		if (philo->info->flag != NOTHING)
		{
			pthread_mutex_unlock(&(philo->info->status));
			break ;
		}
		pthread_mutex_unlock(&(philo->info->status));
		usleep(100);
	}
	return (0);
}
