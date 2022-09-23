/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 22:07:26 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	if (philo->name % 2 == 0)
		usleep(100);
	pthread_mutex_lock(&(forks[philo->left_fork]));
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		pthread_mutex_unlock(&(forks[philo->left_fork]));
		return (1);
	}
	pthread_mutex_lock(&(forks[philo->right_fork]));
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		pthread_mutex_unlock(&(forks[philo->left_fork]));
		pthread_mutex_unlock(&(forks[philo->right_fork]));
		return (1);
	}
	return (0);
}
