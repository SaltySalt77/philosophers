/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_asleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:00 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 19:22:19 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_asleep(t_philo_lst	*philo)
{
	int	repeat_time;
	int	sleep_time;
	int	i;

	i = 0;
	sleep_time = 10000;
	repeat_time = philo->info->p_args[TIME_TO_SLEEP] / 10;
	if (repeat_time == 0)
	{
		repeat_time = philo->info->p_args[TIME_TO_SLEEP];
		sleep_time /= 10;
	}
	print_status(philo, SLEEPING_MSG);
	while (i < repeat_time)
	{
		usleep(sleep_time);
		i++;
	}
}
