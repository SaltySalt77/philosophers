/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_asleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:00 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 19:44:04 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	go_asleep(t_philo_lst	*philo)
{
	struct timeval	start;
	struct timeval	curr;

	if (print_status(philo, SLEEPING_MSG))
		return (1);
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (philo->info->flag != NOTHING)
			return (1);
		if (get_timestamp(&start, &curr)
			>= philo->info->p_args[TIME_TO_SLEEP])
			break ;
		usleep(100);
	}
	return (0);
}
