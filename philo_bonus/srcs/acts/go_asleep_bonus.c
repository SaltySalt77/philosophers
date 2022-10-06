/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_asleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:00 by hyna              #+#    #+#             */
/*   Updated: 2022/10/06 17:02:41 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	go_asleep(t_philo_lst	*philo)
{
	struct timeval	start;
	struct timeval	curr;

	gettimeofday(&start, NULL);
	print_status(philo, SLEEPING_MSG);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (get_timestamp(&start, &curr)
			>= philo->info->p_args[TIME_TO_SLEEP])
			break ;
		usleep(100);
	}
	return (0);
}
