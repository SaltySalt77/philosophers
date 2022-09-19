/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_infos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:12:06 by hyna              #+#    #+#             */
/*   Updated: 2022/09/19 18:29:19 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_line(void)
{
	printf("----------------------------------------------------------------\n");
}

static void	print_info(t_info	*info)
{
	printf("======info======\n");
	printf("args :");
	for(int i = 1; i <= MUST_EAT; i++)
		printf(" [%d]", info->p_args[i]);
	printf("\n");
	for(int i = 1; i <= info->p_args[NBR_OF_PHILO]; i++)
	{
		if (info->p_ids[i] != 0)
			printf("error in p_ids[i]\n");
		else if (info->forks_status[i] != 0)
			printf("error in forks_status[i]\n");
		// else if (info->std_time != -1)
		// 	printf("error ! ! ! ! \n");
	}
}

void	print_philo_infos(t_philo_lst	*head)
{
	print_info(head->info);
	print_line();
	while (head)
	{
		printf("philo name             : [%d]\n", head->name);
		printf("philo's left fork      : [%d]\n", head->left_fork);
		printf("philo's right fork     : [%d]\n", head->right_fork);
		// printf("philo's last meal time : [%ld]\n", head->last_meal_time);
		printf("philo have eaten       : [%d] times\n", head->eaten_time);
		print_line();
		head = head->next;
	}
}
