/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_asleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:00 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 00:20:12 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	go_asleep(t_philo_lst	*philo)
{
	(void) philo;
	// struct timeval	start;
	// struct timeval	curr;

	// gettimeofday(&start, NULL);
	// if (print_status(philo, SLEEPING_MSG))
	// 	return (1);
	// while (1)
	// {
	// 	gettimeofday(&curr, NULL);
	// 	pthread_mutex_lock(&(philo->info->status));
	// 	if (philo->info->flag != NOTHING)
	// 	{
	// 		pthread_mutex_unlock(&(philo->info->status));
	// 		return (1);
	// 	}
	// 	pthread_mutex_unlock(&(philo->info->status));
	// 	if (get_timestamp(&start, &curr)
	// 		>= philo->info->p_args[TIME_TO_SLEEP])
	// 		break ;
	// 	usleep(100);
	// }
	return (0);
}
