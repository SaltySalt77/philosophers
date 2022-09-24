/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 16:43:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo_lst	*philo, char	*msg)
{
	struct timeval		time;

	pthread_mutex_lock(&(philo->info->print));
	pthread_mutex_lock(&(philo->info->status));
	if (philo->info->flag == NOTHING)
	{
		gettimeofday(&time, NULL);
		printf(msg,
			get_timestamp(philo->info->std_time, &time), philo->name);
		if (msg[8] == DEAD_MSG[8])
			philo->info->flag = IS_DEAD;
		pthread_mutex_unlock(&(philo->info->print));
		pthread_mutex_unlock(&(philo->info->status));
		return (0);
	}
	pthread_mutex_unlock(&(philo->info->status));
	pthread_mutex_unlock(&(philo->info->print));
	return (1);
}
