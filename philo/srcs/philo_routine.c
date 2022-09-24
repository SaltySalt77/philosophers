/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 20:15:49 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_stdtime(t_info	*info)
{
	pthread_mutex_lock(&(info->start));
	pthread_mutex_unlock(&(info->start));
}

void	*philo_routine(void	*value)
{
	struct s_philo_lst	*philo;
	pthread_t			monitor;

	philo = (struct s_philo_lst *)value;
	if (pthread_create(&monitor, NULL, &check_death, value) != 0)
		return ((void *) 1);
	wait_stdtime(philo->info);
	if (philo->name % 2 == 0)
		usleep(100);
	if (philo->name == philo->info->p_args[NBR_OF_PHILO])
		usleep(100);
	while (1)
	{
		if (take_fork(philo, philo->info->forks) != NOTHING)
			break ;
		if (eat_spaghetti(philo, philo->info->forks) != NOTHING)
			break ;
		if (go_asleep(philo) != NOTHING)
			break ;
		if (think(philo) != NOTHING)
			break ;
	}
	pthread_join(monitor, NULL);
	return (0);
}
