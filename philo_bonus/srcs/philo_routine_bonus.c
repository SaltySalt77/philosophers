/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 01:41:50 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_stdtime(t_info	*info)
{
	sem_wait(info->start);
	sem_post(info->start);
}

void	*philo_routine(t_philo_lst	*philo)
{
	pthread_t			monitor;

	if (pthread_create(&monitor, NULL, &check_death, philo) != 0)
		return ((void *) 1);
	wait_stdtime(philo->info);
	if (philo->name % 2 == 0)
		usleep(100);
	while (1)
	{
		if (take_fork(philo) != NOTHING)
			break ;
		// if (eat_spaghetti(philo, philo->info->forks) != NOTHING)
		// 	break ;
		// if (go_asleep(philo) != NOTHING)
		// 	break ;
		// if (think(philo) != NOTHING)
		// 	break ;
	}
	pthread_join(monitor, NULL);
	exit(IS_DEAD);
}
