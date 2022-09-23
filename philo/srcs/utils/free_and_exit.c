/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:08:23 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 18:30:26 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 함수 다른 것으로 바꿀 것

int	free_and_exit(t_philo_lst	*philo)
{
	t_philo_lst		*head;
	t_philo_lst		*tmp;
	pthread_mutex_t	print;
	t_info			*info;
	int				i;

	i = 0;
	head = philo->head;
	info = philo->info;
	while (i <= info->p_args[NBR_OF_PHILO])
		pthread_mutex_destroy(&(info->forks[i++]));
	free(info->forks);
	free(info->p_args);
	free(info->p_ids);
	free(info->std_time);
	print = info->print;
	pthread_mutex_destroy(&print);
	free(info);
	while (head)
	{
		tmp = head;
		free(head->last_meal_time);
		head = head->next;
		free(tmp);
	}
	return (1);
}
