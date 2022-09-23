/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:24:53 by hyna              #+#    #+#             */
/*   Updated: 2022/09/23 18:33:46:29 by hyna             ###   ########.fr       */
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

typedef enum e_philo_status
{
	NOTHING = 0,
	IS_DEAD = 1,
	EATEN_ALL = 2
}	t_philo_status;

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
	int					flag;
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
	struct s_philo_lst	*head;
	struct s_philo_lst	*next;
}	t_philo_lst;

/* root directory */
void		*check_death(void	*value);
void		*check_eaten_time(void	*value);
void		*philo_routine(void	*value);
void		wait_stdtime(t_info	*info);

/* act directory */
int			eat_spaghetti(t_philo_lst	*philo, pthread_mutex_t	*forks);
int			go_asleep(t_philo_lst	*philo);
int			take_fork(t_philo_lst	*philo, pthread_mutex_t	*forks);
int			think(t_philo_lst	*philo);
int			print_status(t_philo_lst	*philo, char	*msg);
	//prints status of philo in format msg

/* utils directory */
t_philo_lst	*init_philo_lst(t_info	*info);
t_info		*init_s_info(int ac, char	**av);
t_info		*free_info(t_info	*info);
int			free_philo(t_philo_lst	*philo);
int			get_timestamp(struct timeval *std_time,
				struct timeval *cur_time);

/* test directory */
void		print_philo_infos(t_philo_lst	*head);
#endif