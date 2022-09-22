/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 11:53:17 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_info			*info;
	t_philo_lst		*head;
	t_philo_lst		*curr;
	pthread_t		monitor;	
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
	if (info->p_args[MUST_EAT] != -1)
		pthread_create(&monitor, NULL, &check_eaten_time, head);
	info->std_time = malloc(sizeof(struct timeval));
	gettimeofday(info->std_time, NULL);
	while (1)
		sleep(100);
	return (0);
}
