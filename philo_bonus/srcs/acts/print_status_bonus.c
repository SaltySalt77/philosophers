/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/10/06 17:15:56 by hyna             ###   ########.fr       */
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

int	print_status(t_philo_lst	*philo, const char	*msg)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	usleep(100);
	if (philo->info->flag == IS_DEAD)
		exit(IS_DEAD);
	printf(msg,
		get_timestamp(philo->info->std_time, &time), philo->name);
	if (msg[8] == DEAD_MSG[8])
	{
		philo->info->flag = IS_DEAD;
		sem_post(philo->info->seat);
		exit(IS_DEAD);
	}
	if (philo->info->p_args[NBR_OF_PHILO] == 1)
		return (one_philo(philo->info));
	return (0);
}
