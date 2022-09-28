/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:57 by hyna              #+#    #+#             */
/*   Updated: 2022/09/28 22:05:57 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

/* initializing sturct s_info */

t_info	*free_info(t_info	*info)
{
	free(info->p_args);
	free(info->p_ids);
	free(info);
	return (NULL);
}

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
	if (pthread_mutex_init(&(info->print), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->start), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(info->status), NULL) != 0)
		return (1);
	return (0);
}

static pthread_t	*init_p_ids(int p_nbrs)
{
	pthread_t	*p_ids;

	p_ids = malloc(sizeof(pthread_t) * (p_nbrs + 1));
	if (p_ids == NULL)
		return (NULL);
	memset(p_ids, 0, sizeof(pthread_t) * (p_nbrs + 1));
	return (p_ids);
}

static int	init_semaphores(t_info	*info)
{
	sem_unlink("forks");
	info->forks
		= sem_open("forks", O_CREAT, S_IRWXU, info->p_args[NBR_OF_PHILO]);
	if (info->forks == SEM_FAILED)
		return (1);
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
	if (init_semaphores(info))
		return (free_info(info));
	info->flag = 0;
	info->std_time = NULL;
	return (info);
}
