/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_asleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:42:00 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 02:33:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	go_asleep(t_philo_lst	*philo)
{
	struct timeval	start;
	struct timeval	curr;

	gettimeofday(&start, NULL);
	if (print_status(philo, SLEEPING_MSG))
		return (1);
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
