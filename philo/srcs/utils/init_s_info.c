/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:26:57 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 19:31:59 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* initializing sturct s_info */

static void	init_p_args(int ac, char	**av, t_info	*info)
{
	info->p_args[NBR_OF_PHILO] = ft_atoi(av[NBR_OF_PHILO]);
	info->p_args[TIME_TO_DIE] = ft_atoi(av[TIME_TO_DIE]);
	info->p_args[TIME_TO_EAT] = ft_atoi(av[TIME_TO_EAT]);
	info->p_args[TIME_TO_SLEEP] = ft_atoi(av[TIME_TO_SLEEP]);
	if (ac == 6)
		info->p_args[MUST_EAT] = ft_atoi(av[MUST_EAT]);
	else
		info->p_args[MUST_EAT] = -1;
}

static pthread_t	*init_p_ids(int p_nbrs)
{
	pthread_t	*p_ids;

	p_ids = malloc(sizeof(pthread_t) * (p_nbrs + 1));
	check_alloc(p_ids);
	memset(p_ids, 0, sizeof(pthread_t) * (p_nbrs + 1));
	return (p_ids);
}

static int	init_forks(t_info	*info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->p_args[NBR_OF_PHILO]);
	check_alloc(info->forks);
	while (i < info->p_args[NBR_OF_PHILO])
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL) != 0)
			exit(1);
		i++;
	}
	info->forks_status = malloc(sizeof(int) * (info->p_args[NBR_OF_PHILO] + 1));
	check_alloc(info->forks_status);
	memset(info->forks_status, 0,
		sizeof(int) * (info->p_args[NBR_OF_PHILO] + 1));
	return (0);
}

t_info	*init_s_info(int ac, char	**av)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	check_alloc(info);
	info->p_args = malloc(sizeof(int) * 6);
	check_alloc(info->p_args);
	init_p_args(ac, av, info);
	info->p_ids = init_p_ids(info->p_args[NBR_OF_PHILO]);
	init_forks(info);
	info->std_time = -1;
	return (info);
}
