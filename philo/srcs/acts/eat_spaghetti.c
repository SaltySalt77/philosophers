/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 09:56:10 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//usleep 100  안에서 시간체크 

void	eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	struct timeval	start;
	struct timeval	curr;

	print_status(philo, EATING_MSG);
	gettimeofday(&start, NULL);
	while (1)
	{
		gettimeofday(&curr, NULL);
		if (get_timestamp(&start, &curr)
			>= philo->info->p_args[TIME_TO_EAT])
			break ;
		usleep(100);
	}
	pthread_mutex_unlock(&(forks[philo->left_fork]));
	pthread_mutex_unlock(&(forks[philo->right_fork]));
}
