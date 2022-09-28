/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 01:49:37 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* free info */

t_info	*free_info(t_info	*info)
{
	free(info->p_args);
	free(info->p_ids);
	free(info);
	return (NULL);
}

static void	unlink_semaphores(t_info	*info)
{
	sem_close(info->lforks);
	sem_unlink("lforks");
	sem_close(info->rforks);
	sem_unlink("rforks");
	sem_close(info->print);
	sem_unlink("print");
	sem_close(info->start);
	sem_unlink("start");
}

int	free_philo(t_philo_lst	*philo)
{
	t_philo_lst		*tmp;
	t_info			*info;

	info = philo->info;
	unlink_semaphores(philo->info);
	free(info->std_time);
	free_info(info);
	while (philo)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp->last_meal_time);
		memset(tmp, 0, sizeof(t_philo_lst));
		free(tmp);
	}
	return (1);
}
