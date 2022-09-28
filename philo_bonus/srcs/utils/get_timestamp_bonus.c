/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:46:09 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 00:48:03 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_timestamp(struct timeval *std_time, struct timeval *cur_time)
{
	double	timestamp;

	fprintf(stderr, "imhere time\n");
	timestamp = (cur_time->tv_sec) * 1000 + (cur_time->tv_usec) / 1000;
	fprintf(stderr, "imhere time\n");
	timestamp -= (std_time->tv_sec) * 1000 + (std_time->tv_usec) / 1000;
	fprintf(stderr, "imhere time\n");
	return ((int) timestamp);
}
