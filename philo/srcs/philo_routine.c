/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 21:23:04 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_stdtime(t_info	*info)
{
	while (1)
	{
		if (info->std_time != -1)
			break ;
		usleep(1);
	}
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
		pthread_mutex_lock(&(philo->info->print));
		gettimeofday(&time, NULL);
		printf("[%d] Started philo[%d]\n",
			(time.tv_usec - philo->info->std_time), philo->name);
		pthread_mutex_unlock(&(philo->info->print));
		break ;
		//take_fork()
		//think()
	}
	return (0);
}
