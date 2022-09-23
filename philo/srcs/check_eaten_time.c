/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eaten_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:12:54 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 19:06:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_eaten_time(void	*value)
{
	t_philo_lst		*philo;
	t_philo_lst		*curr;
	int				min_time;

	philo = (t_philo_lst *) value;
	wait_stdtime(philo->info);
	while (1)
	{
		curr = philo;
		min_time = philo->info->p_args[MUST_EAT];
		while (curr)
		{
			if (curr->eaten_time < min_time)
				min_time = curr->eaten_time;
			curr = curr->next;
		}
		if (min_time == philo->info->p_args[MUST_EAT])
			break ;
		usleep(100);
	}
	philo->info->flag = EATEN_ALL;
	return (0);
}
