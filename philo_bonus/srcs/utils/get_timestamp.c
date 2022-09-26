/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:09 by hyna              #+#    #+#             */
/*   Updated: 2022/09/24 20:32:35 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp(struct timeval *std_time, struct timeval *cur_time)
{
	double	timestamp;

	timestamp = (cur_time->tv_sec) * 1000 + (cur_time->tv_usec) / 1000;
	timestamp -= (std_time->tv_sec) * 1000 + (std_time->tv_usec) / 1000;
	return ((int) timestamp);
}
