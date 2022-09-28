/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/09/28 21:52:54 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	one_philo(t_info	*info)
{
	while (1)
	{
		pthread_mutex_lock(&(info->status));
		if (info->flag != NOTHING)
			break ;
		pthread_mutex_unlock(&(info->status));
		usleep(100);
	}
	pthread_mutex_unlock(&(info->status));
	return (1);
}

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
		pthread_mutex_unlock(&(philo->info->status));
		pthread_mutex_unlock(&(philo->info->print));
		if (philo->left_fork == philo->right_fork)
			return (one_philo(philo->info));
		return (0);
	}
	pthread_mutex_unlock(&(philo->info->status));
	pthread_mutex_unlock(&(philo->info->print));
	return (1);
}
