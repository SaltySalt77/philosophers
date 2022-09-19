/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:42:58 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 16:26:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_stdtime(t_info	*info)
{
	while (1)
	{
		if (info->std_time != -1)
			break ;
		usleep(10);
	}
}

void	*philo_routine(void	*value)
{
	struct s_philo_lst	*philo;

	philo = (struct s_philo_lst *)value;
	wait_stdtime(philo->info);
	while (1)
	{
		take_fork(philo, philo->info->forks);
		eat_spaghetti(philo, philo->info->forks);
		//sleep()
		//think()
	}
	return (0);
}
