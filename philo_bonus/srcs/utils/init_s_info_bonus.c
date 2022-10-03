/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:57 by hyna              #+#    #+#             */
/*   Updated: 2022/10/03 18:39:49 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* initializing struct s_info */

/* initialize p_arguments with argv */

static int	init_p_args(int ac, char	**av, t_info	*info)
{
	info->p_args[NBR_OF_PHILO] = ft_atoi(av[NBR_OF_PHILO]);
	info->p_args[TIME_TO_DIE] = ft_atoi(av[TIME_TO_DIE]);
	info->p_args[TIME_TO_EAT] = ft_atoi(av[TIME_TO_EAT]);
	info->p_args[TIME_TO_SLEEP] = ft_atoi(av[TIME_TO_SLEEP]);
	if (ac == 6)
	{
		info->p_args[MUST_EAT] = ft_atoi(av[MUST_EAT]);
		if (info->p_args[MUST_EAT] < 0)
			return (1);
	}
	else
		info->p_args[MUST_EAT] = -1;
	return (0);
}

/* initialze double string array of pid of philos */

static pid_t	*init_p_ids(int p_nbrs)
{
	pid_t	*p_ids;

	p_ids = malloc(sizeof(pid_t) * (p_nbrs + 1));
	if (p_ids == NULL)
		return (NULL);
	memset(p_ids, 0, sizeof(pid_t) * (p_nbrs + 1));
	return (p_ids);
}

/* open semaphores for global use */

static int	init_forks(t_info	*info)
{
	int	i;

	i = 0;
	if (info->p_args[NBR_OF_PHILO] % 2)
		i = 1;
	sem_unlink("lforks");
	info->lforks = sem_open("lforks", O_CREAT, S_IRWXU,
			info->p_args[NBR_OF_PHILO] / 2 + i);
	if (info->lforks == SEM_FAILED)
		return (1);
	sem_unlink("rforks");
	info->rforks = sem_open("rforks", O_CREAT, S_IRWXU,
			info->p_args[NBR_OF_PHILO] / 2);
	if (info->rforks == SEM_FAILED)
		return (1);
	sem_unlink("meal");
	info->meal = sem_open("meal", O_CREAT, S_IRWXU,
			info->p_args[NBR_OF_PHILO]);
	if (info->meal == SEM_FAILED)
		return (1);
	return (0);
}

static int	init_semaphores(t_info	*info)
{
	sem_unlink("print");
	info->print
		= sem_open("print", O_CREAT, S_IRWXU, 1);
	if (info->print == SEM_FAILED)
		return (1);
	sem_unlink("start");
	info->start
		= sem_open("start", O_CREAT, S_IRWXU, 1);
	if (info->start == SEM_FAILED)
		return (1);
	sem_unlink("seat");
	info->seat
		= sem_open("seat", O_CREAT, S_IRWXU, info->p_args[NBR_OF_PHILO]);
	if (info->seat == SEM_FAILED)
		return (1);
	return (0);
}

t_info	*init_s_info(int ac, char	**av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (info == NULL)
		return (NULL);
	info->p_ids = NULL;
	info->p_args = malloc(sizeof(int) * 6);
	if (info->p_args == NULL)
		return (free_info(info));
	if (init_p_args(ac, av, info))
		return (free_info(info));
	info->p_ids = init_p_ids(info->p_args[NBR_OF_PHILO]);
	if (info->p_ids == NULL)
		return (free_info(info));
	info->std_time = malloc(sizeof(struct timeval));
	if (info->std_time == NULL)
		return (free_info(info));
	if (init_forks(info))
		return (free_info(info));
	if (init_semaphores(info))
		return (free_info(info));
	info->flag = 0;
	return (info);
}
