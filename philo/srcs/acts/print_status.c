/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 18:44:52 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo_lst	*philo, char	*msg)
{
	struct timeval		time;

	pthread_mutex_lock(&(philo->info->print));
	if (philo->info->flag != IS_DEAD && philo->info->flag != EATEN_ALL)
	{
		gettimeofday(&time, NULL);
		printf(msg,
			get_timestamp(philo->info->std_time, &time), philo->name);
		if (msg[8] == DEAD_MSG[8])
			philo->info->flag = IS_DEAD;
		pthread_mutex_unlock(&(philo->info->print));
		return (0);
	}
	pthread_mutex_unlock(&(philo->info->print));
	return (1);
}
