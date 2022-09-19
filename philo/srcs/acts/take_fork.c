/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 18:06:34 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	if (philo->name % 2 == 0)
		usleep(5);
	pthread_mutex_lock(&(forks[philo->left_fork]));
	pthread_mutex_lock(&(forks[philo->right_fork]));
	print_status(philo, TAKEN_FORK_MSG);
}
