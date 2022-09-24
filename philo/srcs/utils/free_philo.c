/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 16:11:40 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_philo(t_philo_lst	*philo)
{
	t_philo_lst		*head;
	t_philo_lst		*tmp;
	t_info			*info;
	int				i;

	i = 0;
	head = philo->head;
	info = philo->info;
	while (i <= info->p_args[NBR_OF_PHILO])
		pthread_mutex_destroy(&(info->forks[i++]));
	pthread_mutex_destroy(&(info->print));
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
