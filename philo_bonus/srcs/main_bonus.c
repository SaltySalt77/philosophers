/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/09/29 01:42:48 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	kill_philos(t_info	*info)
{
	int	i;

	i = 1;
	while (i <= info->p_args[NBR_OF_PHILO])
		kill(info->p_ids[i++], SIGKILL);
	return (1);
}

static int	fork_philos(t_philo_lst	*philo, t_info	*info)
{
	int	i;

	i = 1;
	gettimeofday(info->std_time, NULL);
	while (i <= info->p_args[NBR_OF_PHILO])
	{
		info->p_ids[i] = fork();
		if (info->p_ids[i] == 0)
			philo_routine(philo);
		else if (info->p_ids < 0)
			return (1);
		i++;
		philo = philo->next;
		sem_wait(info->seat);
	}
	return (0);
}

static void	wait_philos(t_info	*info)
{
	// int		status;
	// // int		exit_code;v
	// pid_t	wpid;

	// wpid = 0;
	sem_post(info->start);
	sem_wait(info->seat);
	kill_philos(info);
}

int	validate_arguments(char	**argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0)
			{
				if (ft_isdigit(argv[i][j]) == 0 && argv[i][j] != '+')
					return (1);
				else if (argv[i][j] == '+' && argv[i][j + 1] == 0)
					return (1);
			}
			else if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char	**argv)
{
	t_info			*info;
	t_philo_lst		*head;

	if (argc < 5 || argc > 6)
		return (1);
	if (validate_arguments(argv))
		return (1);
	info = init_s_info(argc, argv);
	head = init_philo_lst(info);
	sem_wait(info->start);
	if (fork_philos(head, info))
	{
		free_philo(head);
		return (1);
	}
	wait_philos(info);
	free_philo(head);
	return (0);
}
