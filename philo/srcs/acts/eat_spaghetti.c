/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_spaghetti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:19 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 16:25:13 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	int	repeat_times;
	int	i;

	i = 0;
	repeat_times = philo->info->p_args[TIME_TO_EAT];
	print_status(philo, EATING_MSG);
	while (i < repeat_times)
	{
		usleep(1000);
		i++;
	}
	pthread_mutex_unlock(&(forks[philo->left_fork]));
	pthread_mutex_unlock(&(forks[philo->right_fork]));
}
