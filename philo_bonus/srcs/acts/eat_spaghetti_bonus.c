/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/10/03 18:40:27 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	add_eaten_time_post(t_philo_lst	*philo)
{
	sem_post(philo->info->lforks);
	sem_post(philo->info->rforks);
	philo->eaten_time++;
	if (philo->eaten_time == philo->info->p_args[MUST_EAT])
		sem_post(philo->info->meal);
}

static int	init_last_meat_time(t_philo_lst	*philo)
{
	if (philo->last_meal_time == NULL)
	{
		philo->last_meal_time = malloc(sizeof(struct timeval));
		if (philo->last_meal_time == NULL)
			return (1);
	}
	gettimeofday(philo->last_meal_time, NULL);
	return (0);
}

int	eat_spaghetti(t_philo_lst	*philo)
{
	struct timeval	curr;

	if (init_last_meat_time(philo))
		return (1);
	if (print_status(philo, EATING_MSG))
		return (1);
	while (!usleep(100))
	{
		gettimeofday(&curr, NULL);
		if (get_timestamp(philo->last_meal_time, &curr)
			>= philo->info->p_args[TIME_TO_EAT])
			break ;
	}
	add_eaten_time_post(philo);
	return (0);
}
