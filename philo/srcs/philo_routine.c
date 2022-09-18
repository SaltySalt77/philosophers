/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 21:27:19 by hyna             ###   ########.fr       */
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
// 시간 순 대로 프린트하도록 뮤텍스 락을 걸면 너무 시간이 지연됨.
// 뮤텍스 락을 걸지 않을 경우 시간순대로 나오지 않음

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
