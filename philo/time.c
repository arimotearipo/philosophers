/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:10:47 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/19 18:14:39 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(void)
{
	long long		sec_to_usec;
	struct timeval	starttime;

	gettimeofday(&starttime, NULL);
	sec_to_usec = (long long)(starttime.tv_sec * 1000000);
	starttime.tv_usec = (long long)(starttime.tv_usec);
	return ((sec_to_usec + starttime.tv_usec) / 1000);
}

void	msleep(int n)
{
	usleep(n * 1000);
}
