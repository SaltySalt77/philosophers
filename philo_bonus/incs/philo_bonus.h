/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:49:18 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 01:46:36 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <signal.h>

// for semaphores
# include <semaphore.h>
# include <sys/stat.h>

// for libft_functions
# include "philo_utils_bonus.h"

//mecros for printing state change
# define TAKEN_FORK_MSG "%d %d has taken a fork\n"
# define EATING_MSG "%d %d is eating\n"
# define SLEEPING_MSG "%d %d is sleeping\n"
# define THINKING_MSG "%d %d is thinking\n"
# define DEAD_MSG "%d %d died\n"

typedef enum e_info_idx
{
	NBR_OF_PHILO = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	MUST_EAT = 5
}	t_info_idx;

typedef enum e_philo_status
{
	NOTHING = 0,
	IS_DEAD = 1,
	EATEN_ALL = 2
}	t_philo_status;

typedef struct s_info
{
	int					*p_args;
	pid_t				*p_ids;
	sem_t				*lforks;
	sem_t				*rforks;
	sem_t				*print;
	sem_t				*start;
	sem_t				*seat;
	pthread_mutex_t		status; // <<??
	int					flag;
	struct timeval		*std_time;
}	t_info;

typedef struct s_philo_lst
{
	int					name;
	struct timeval		*last_meal_time;
	int					eaten_time;
	int					last_act;
	struct s_info		*info;
	struct s_philo_lst	*next;
}	t_philo_lst;

/* root directory */
void		*check_death(void	*value);
void		*philo_routine(t_philo_lst	*philo);
void		wait_stdtime(t_info	*info);

/* act directory */
int			eat_spaghetti(t_philo_lst	*philo);
int			go_asleep(t_philo_lst	*philo);
int			take_fork(t_philo_lst	*philo);
int			think(t_philo_lst	*philo);
int			print_status(t_philo_lst	*philo, const char	*msg);
	//prints status of philo in format msg

/* utils directory */
t_philo_lst	*init_philo_lst(t_info	*info);
t_info		*init_s_info(int ac, char	**av);
t_info		*free_info(t_info	*info);
int			free_philo(t_philo_lst	*philo);
int			get_timestamp(struct timeval *std_time,
				struct timeval *cur_time);

#endif