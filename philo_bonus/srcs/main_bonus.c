/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/10/06 16:57:50 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*kill_philos(void	*value)
{
	int		i;
	t_info	*info;

	info = (t_info *)value;
	i = 1;
	sem_wait(info->seat);
	while (i <= info->p_args[NBR_OF_PHILO])
	{
		kill(info->p_ids[i++], SIGKILL);
		sem_post(info->meal);
	}
	return (0);
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
		else if (info->p_ids[i] < 0)
			return (1);
		i++;
		philo = philo->next;
		sem_wait(info->seat);
		sem_wait(info->meal);
	}
	return (0);
}

static void	wait_philos(t_info	*info)
{
	pthread_t	k_monitor;
	pthread_t	m_monitor;
	pid_t		wpid;
	int			status;
	int			i;

	i = 1;
	if (pthread_create(&k_monitor, NULL, &kill_philos, (void *)info))
	{
		while (i <= info->p_args[NBR_OF_PHILO])
			kill(info->p_ids[i++], SIGKILL);
		exit(1);
	}
	if (pthread_create(&m_monitor, NULL, &check_eaten_time, (void *)info))
	{
		while (i <= info->p_args[NBR_OF_PHILO])
			kill(info->p_ids[i++], SIGKILL);
		exit(1);
	}
	sem_post(info->start);
	wpid = 1;
	while (wpid > 0)
		wpid = waitpid(-1, &status, 0);
	pthread_join(k_monitor, NULL);
	pthread_join(m_monitor, NULL);
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
				if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+')
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
