/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:18:20 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 19:53:28 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void	*value)
{
	t_philo_lst		*philo;
	struct timeval	curr;

	philo = (t_philo_lst *) value;
	wait_stdtime(philo->info);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (philo->last_meal_time && get_timestamp(philo->last_meal_time, &curr)
			> philo->info->p_args[TIME_TO_DIE])
			print_status(philo, DEAD_MSG);
		else if (!(philo->last_meal_time)
			&& get_timestamp(philo->info->std_time, &curr)
			> philo->info->p_args[TIME_TO_DIE])
			print_status(philo, DEAD_MSG);
		if (philo->info->flag != NOTHING)
			break ;
		usleep(100);
	}
	return (0);
}
