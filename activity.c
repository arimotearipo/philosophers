/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:11:21 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/21 23:44:36 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	long long	time;
	
	time = ft_time();
	philo->eating = 1;
	philo->lastate = time;
	printf(YEL "%lld %d is eating\n", time, philo->id);
	msleep(philo->life->time_to_eat);
	philo->eaten += 1;
	philo->eating = 0;
}

void	philo_think(t_philo *philo)
{
	printf(WHT "%lld %d is thinking\n", ft_time(), philo->id);
}

void	philo_sleep(t_philo *philo)
{
	printf(PUR "%lld %d is sleeping\n", ft_time(), philo->id);
	msleep(philo->life->time_to_sleep);
}
