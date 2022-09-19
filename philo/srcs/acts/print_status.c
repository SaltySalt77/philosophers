/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:47:21 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 18:28:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo_lst	*philo, char	*msg)
{
	struct timeval		time;

	pthread_mutex_lock(&(philo->info->print));
	gettimeofday(&time, NULL);
	printf(msg,
		get_timestamp(philo->info->std_time, &time), philo->name);
	pthread_mutex_unlock(&(philo->info->print));
}
