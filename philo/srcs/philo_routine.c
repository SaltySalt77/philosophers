/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 11:54:47 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_stdtime(t_info	*info)
{
	while (1)
	{
		if (info->std_time)
			break ;
		usleep(10);
	}
}

void	*philo_routine(void	*value)
{
	struct s_philo_lst	*philo;
	pthread_t			monitor;

	philo = (struct s_philo_lst *)value;
	if (pthread_create(&monitor, NULL, &check_death, value) != 0)
		exit(1);
	wait_stdtime(philo->info);
	while (1)
	{
		take_fork(philo, philo->info->forks);
		eat_spaghetti(philo, philo->info->forks);
		go_asleep(philo);
		think(philo);
	}
	return (0);
}
