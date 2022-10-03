/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eaten_time_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:43:04 by hyna              #+#    #+#             */
/*   Updated: 2022/10/03 18:58:40 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_eaten_time(void	*value)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *) value;
	while (i < info->p_args[NBR_OF_PHILO])
	{
		sem_wait(info->meal);
		i++;
	}
	sem_post(info->seat);
	return (0);
}
