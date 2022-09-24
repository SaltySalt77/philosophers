/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 19:30:15 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	add_eaten_time_unlock(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	pthread_mutex_lock(&(philo->info->status));
	philo->eaten_time++;
	pthread_mutex_unlock(&(philo->info->status));
	pthread_mutex_unlock(&(forks[philo->left_fork]));
	pthread_mutex_unlock(&(forks[philo->right_fork]));
}

static int	init_last_meat_time(t_philo_lst	*philo)
{
	pthread_mutex_lock(&(philo->info->meal[philo->name]));
	if (philo->last_meal_time == NULL)
	{
		philo->last_meal_time = malloc(sizeof(struct timeval));
		if (philo->last_meal_time == NULL)
			return (1);
	}
	gettimeofday(philo->last_meal_time, NULL);
	pthread_mutex_unlock(&(philo->info->meal[philo->name]));
	return (0);
}

int	eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	struct timeval	curr;

	if (init_last_meat_time(philo))
		return (1);
	if (print_status(philo, EATING_MSG))
		return (1);
	while (1)
	{
		pthread_mutex_lock(&(philo->info->status));
		if (philo->info->flag != NOTHING)
		{
			pthread_mutex_unlock(&(philo->info->status));
			break ;
		}
		pthread_mutex_unlock(&(philo->info->status));
		gettimeofday(&curr, NULL);
		if (get_timestamp(philo->last_meal_time, &curr)
			>= philo->info->p_args[TIME_TO_EAT])
			break ;
		usleep(100);
	}
	add_eaten_time_unlock(philo, forks);
	return (philo->info->flag);
}
