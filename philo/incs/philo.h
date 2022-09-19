/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:24:53 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 19:07:05 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

// for libft_functions
# include "philo_utils.h"

//test msg define need to rm before eval
# define START_MSG "[%d] Started philo[%d]\n"

//mecros for printing state change
# define TAKEN_FORK_MSG "%dms %d has taken a fork\n"
# define EATING_MSG "%dms %d is eating\n"
# define SLEEPING_MSG "%dms %d is sleeping\n"
# define THINKING_MSG "%dms %d is thinking\n"
# define DEAD_MSG "%dms %d died\n"

typedef enum e_info_idx
{
	NBR_OF_PHILO = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	MUST_EAT = 5
}	t_info_idx;

// maybe it'll be needed to remove
typedef enum e_fork_status
{
	UNTAKEN = 0,
	TAKEN = 1
}	t_fork_status;

// maybe it'll be needed to remove
typedef enum e_last_act
{
	EATING = 1,
	SLEEPING= 2,
	THINKING = 3
}	t_last_act;

typedef struct s_info
{
	int					*p_args;
	pthread_t			*p_ids;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	int					*forks_status;
	struct timeval		*std_time;
}	t_info;

typedef struct s_philo_lst
{
	int					name;
	int					left_fork;
	int					right_fork;
	struct timeval		*last_meal_time;
	int					eaten_time;
	int					last_act;
	struct s_info		*info;
	struct s_philo_lst	*next;
}	t_philo_lst;

/* root directory */
void		*philo_routine(void	*value);

/* act directory */
void		eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks);
void		go_asleep(t_philo_lst	*philo);
void		take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks);
void		think(t_philo_lst	*philo);
void		print_status(t_philo_lst	*philo, char	*msg);
	//prints status of philo in format msg

/* utils directory */
t_philo_lst	*init_philo_lst(t_info	*info);
t_info		*init_s_info(int ac, char	**av);
int			check_alloc(void	*allocated);
	// check if allocated is NULL and exit when it is NULL
int			get_timestamp(struct timeval *std_time,
				struct timeval *cur_time);

/* test directory */
void		print_philo_infos(t_philo_lst	*head);
#endif