/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 11:42:44 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	struct timeval	curr;

	if (philo->last_meal_time == NULL)
	{
		philo->last_meal_time = malloc(sizeof(struct timeval));
		check_alloc(philo->last_meal_time);
	}
	gettimeofday(philo->last_meal_time, NULL);
	print_status(philo, EATING_MSG);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (get_timestamp(philo->last_meal_time, &curr)
			>= philo->info->p_args[TIME_TO_EAT])
			break ;
		usleep(100);
	}
	philo->eaten_time++;
	pthread_mutex_unlock(&(forks[philo->left_fork]));
	pthread_mutex_unlock(&(forks[philo->right_fork]));
}
