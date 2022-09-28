/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 00:38:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	take_fork(t_philo_lst	*philo)
{
	if (philo->name % 2 == 0)
		usleep(100);
	sem_wait(philo->info->forks);
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		// sem_post(&(philo->info->forks));
		return (1);
	}
	sem_wait(philo->info->forks);
	if (print_status(philo, TAKEN_FORK_MSG))
	{
		// sem_post(philo->info->forks);
		// sem_post(philo->info->forks);
		return (1);
	}
	return (0);
}