/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 16:42:15 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks)
{
	pthread_mutex_lock(&(forks[philo->left_fork]));
	pthread_mutex_lock(&(forks[philo->right_fork]));
	print_status(philo, TAKEN_FORK_MSG);
}
