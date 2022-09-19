/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salt <salt@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 20:55:05 by salt             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_stdtime(t_info	*info)
{
	while (1)
	{
		if (info->std_time != -1)
			break ;
		usleep(10);
	}
}

static int	get_timestamp(suseconds_t std_time, suseconds_t	cur_time)
{
	int	timestamp;

	timestamp = (cur_time - std_time) / 1000;
	return (timestamp);
}

void	*philo_routine(void	*value)
{
	struct s_philo_lst	*philo;
	struct timeval		time;

	philo = (struct s_philo_lst *)value;
	if (philo == NULL)
		printf("WHY???");
	wait_stdtime(philo->info);
	while (1)
	{
		//pthread_mutex_lock(&(philo->info->print));
		gettimeofday(&time, NULL);
		printf(START_MSG,
			get_timestamp(philo->info->std_time, time.tv_usec), philo->name);
		//pthread_mutex_unlock(&(philo->info->print));
		break ;
		//take_fork()
		//think()
	}
	return (0);
}
