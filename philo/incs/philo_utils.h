/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:43:55 by hyna              #+#    #+#             */
/*   Updated: 2022/09/22 10:43:53 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <stddef.h>

size_t	ft_strlen(const char	*s);
int		ft_atoi(const char	*nptr);
int		ft_isdigit(int c);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);

#endif