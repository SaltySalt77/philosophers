/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:40:12 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 10:44:19 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

size_t	ft_strlen(const char	*s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
