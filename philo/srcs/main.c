/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 21:19:33 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_info			*info;
	t_philo_lst		*head;
	t_philo_lst		*curr;
	struct timeval	time;
	int				i;

	(void) argv;
	if (argc < 5 || argc > 6)
		return (1);
	info = init_s_info(argc, argv);
	head = init_philo_lst(info);
	curr = head;
	//print_philo_infos(head);	//testcode
	i = 1;
	while (curr && i <= info->p_args[NBR_OF_PHILO])
	{
		if (pthread_create(&(info->p_ids[i]), NULL,
				&philo_routine, (void *)curr) != 0)
			exit(1);
		curr = curr->next;
	}
	gettimeofday(&time, NULL);
	info->std_time = time.tv_usec;
	while (1)
		sleep(100);
	return (0);
}
