/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/28 23:08:41 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	unlink_semaphores(void)
{
	sem_close("forks");
	sem_unlink("forks");
	sem_close("print");
	sem_unlink("print");
	sem_close("start");
	sem_unlink("start");
}

int	free_philo(t_philo_lst	*philo)
{
	t_philo_lst		*head;
	t_philo_lst		*tmp;
	t_info			*info;

	head = philo->head;
	info = philo->info;
	unlink_semaphores();
	free(info->std_time);
	free_info(info);
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->last_meal_time);
		memset(tmp, 0, sizeof(t_philo_lst));
		free(tmp);
	}
	return (1);
}
