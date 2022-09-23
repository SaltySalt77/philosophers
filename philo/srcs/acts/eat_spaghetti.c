/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 19:43:59 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	struct timeval	curr;

	if (philo->last_meal_time == NULL)
	{
		philo->last_meal_time = malloc(sizeof(struct timeval));
		if (philo->last_meal_time == NULL)
			return (1);
	}
	gettimeofday(philo->last_meal_time, NULL);
	if (print_status(philo, EATING_MSG))
		return (1);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (philo->info->flag != NOTHING)
			return (1);
		else if (get_timestamp(philo->last_meal_time, &curr)
			>= philo->info->p_args[TIME_TO_EAT])
			break ;
		usleep(100);
	}
	philo->eaten_time++;
	pthread_mutex_unlock(&(forks[philo->left_fork]));
	pthread_mutex_unlock(&(forks[philo->right_fork]));
	return (philo->info->flag);
}
