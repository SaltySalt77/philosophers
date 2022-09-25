/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/09/25 16:13:48 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_threads(t_info	*info, pthread_t	monitor)
{
	int	i;

	i = 1;
	while (i <= info->p_args[NBR_OF_PHILO])
		pthread_join(info->p_ids[i++], NULL);
	if (info->p_args[MUST_EAT] != -1)
		pthread_join(monitor, NULL);
}

int	create_threads(t_info	*info, t_philo_lst	*philo, pthread_t *monitor)
{
	int				i;
	t_philo_lst		*curr;

	i = 1;
	curr = philo;
	pthread_mutex_lock(&(info->start));
	while (curr)
	{
		if (pthread_create(&(info->p_ids[i++]), NULL,
				&philo_routine, (void *)curr) != 0)
			return (1);
		curr = curr->next;
	}
	if (info->p_args[MUST_EAT] != -1)
		pthread_create(monitor, NULL, &check_eaten_time, philo);
	info->std_time = malloc(sizeof(struct timeval));
	if (info->std_time == NULL)
		return (1);
	gettimeofday(info->std_time, NULL);
	pthread_mutex_unlock(&(info->start));
	return (0);
}

int	validate_arguments(char	**argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_info			*info;
	t_philo_lst		*head;
	pthread_t		monitor;

	if (argc < 5 || argc > 6)
		return (1);
	if (validate_arguments(argv))
		return (1);
	info = init_s_info(argc, argv);
	head = init_philo_lst(info);
	if (create_threads(info, head, &monitor))
		return (1);
	wait_threads(info, monitor);
	free_philo(head);
	return (0);
}
