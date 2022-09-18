/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:24:53 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 20:33:27 by hyna             ###   ########.fr       */
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

typedef enum e_info_idx
{
	NBR_OF_PHILO = 1,
	TIME_TO_DIE = 2,
	TIME_TO_EAT = 3,
	TIME_TO_SLEEP = 4,
	MUST_EAT = 5
}	t_info_idx;

typedef enum e_fork_status
{
	UNTAKEN = 0,
	TAKEN = 1
}	t_fork_status;

typedef enum e_last_act
{
	EATING = 1,
	SLEEPING= 2,
	THINKING = 3
}	t_last_act;

typedef struct s_info
{
	int				*p_args;
	pthread_t		*p_ids;
	pthread_mutex_t	*forks;
	int				*forks_status;
	suseconds_t		std_time;
}	t_info;

typedef struct s_philo_lst
{
	int					name;
	int					left_fork;
	int					right_fork;
	suseconds_t			last_meal_time;
	int					eaten_time;
	int					last_act;
	struct s_info		*info;
	struct s_philo_lst	*next;
}	t_philo_lst;

/* utils directory */
t_philo_lst	*init_philo_lst(t_info	*info);
t_info		*init_s_info(int ac, char	**av);
int			check_alloc(void	*allocated);
	// check if allocated is NULL and exit when it is NULL

/* test directory */
void		print_philo_infos(t_philo_lst	*head);
#endif