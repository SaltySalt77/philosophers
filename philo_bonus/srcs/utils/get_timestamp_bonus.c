/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:09 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 01:10:55 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_timestamp(struct timeval *std_time, struct timeval *cur_time)
{
	int	timestamp;
	int	std_timestamp;

	timestamp = (cur_time->tv_sec) * 1000 + (cur_time->tv_usec) / 1000;
	std_timestamp = (std_time->tv_sec) * 1000 + (std_time->tv_usec) / 1000;
	timestamp = timestamp - std_timestamp;
	return ((int) timestamp);
}
