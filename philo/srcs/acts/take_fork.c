/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 20:15:22 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	pthread_mutex_lock(&(forks[philo->left_fork]));
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		pthread_mutex_unlock(&(forks[philo->left_fork]));
		return (1);
	}
	if (philo->name == philo->info->p_args[NBR_OF_PHILO])
		usleep(100);
	pthread_mutex_lock(&(forks[philo->right_fork]));
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		pthread_mutex_unlock(&(forks[philo->left_fork]));
		pthread_mutex_unlock(&(forks[philo->right_fork]));
		return (1);
	}
	return (0);
}
