/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:24:53 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 16:37:34 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_infos
{
	NBR_OF_PHILOS = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	MUST_EAT = 5
}	t_infos;

typedef enum e_fork_status
{
	UNTAKEN = 0,
	TAKEN = 1
}	t_fork_status;

typedef struct s_info
{
	int				p_count;
	pthread_t		*p_ids;
	pthread_mutex_t	*forks;
	int				*forks_status;
	suseconds_t		std_time;
}	t_info;

typedef struct s_philos
{
	int				nbr;
	int				left_fork;
	int				right_fork;
	suseconds_t		last_meal_time;
	struct s_info	*info;
}	t_philos;

#endif