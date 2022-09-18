/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:15:30 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 19:04:40 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_info		*info;
	t_philo_lst	*head;
	t_philo_lst	*curr;

	(void) argv;
	if (argc < 5 || argc > 6)
		return (1);
	info = init_s_info(argc, argv);
	head = init_philo_lst(info);
	curr = head;
	// 스레드 생성
	while (1)
		sleep(100);
	return (0);
}
