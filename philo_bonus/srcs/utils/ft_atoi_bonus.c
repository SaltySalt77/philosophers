/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:42:48 by hyna              #+#    #+#             */
/*   Updated: 2022/09/18 17:46:36 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

static char	*check_space(char	*str)
{
	while ((*str == ' ') || (*str == '\n') || (*str == '\t')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	return (str);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		np;
	int		n;
	long	result;

	str = (char *)nptr;
	np = 1;
	result = 0;
	str = check_space(str);
	if (*str == '-')
	{
		np = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = *str - 48;
		result = result * 10 + n;
		str++;
	}
	result = result * np;
	return ((int)result);
}
