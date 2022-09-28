/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 00:08:56 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	one_philo(t_info	*info)
{
	while (1)
	{
		if (info->flag != NOTHING)
			break ;
		usleep(100);
	}
	return (1);
}

int	print_status(t_philo_lst	*philo, char	*msg)
{
	struct timeval		time;

	sem_wait(&(philo->info->print));
	if (philo->info->flag == NOTHING)
	{
		gettimeofday(&time, NULL);
		printf(msg,
			get_timestamp(philo->info->std_time, &time), philo->name);
		if (msg[8] == DEAD_MSG[8])
			philo->info->flag = IS_DEAD;
		sem_post(&(philo->info->print));
		if (philo->name == 1)
			return (one_philo(philo->info));
		return (0);
	}
	sem_post(&(philo->info->print));
	return (1);
}
