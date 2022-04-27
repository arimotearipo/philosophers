/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:11:21 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:33:11 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_takefork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	if (philo->life->death == 0)
		printf(BLU "%lld %d has taken a fork\n", ft_time(), philo->id);
	pthread_mutex_unlock(&(philo->life->print));
}

void	philo_eat(t_philo *philo)
{
	philo->eating = 1;
	pthread_mutex_lock(&(philo->life->print));
	if (philo->life->death == 0)
		printf(YEL "%lld %d is eating\n", ft_time(), philo->id);
	pthread_mutex_unlock(&(philo->life->print));
	philo->lastate = ft_time();
	msleep(philo->life->time_to_eat, ft_time());
	philo->eaten += 1;
	philo->eating = 0;
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	if (philo->life->death == 0)
		printf(WHT "%lld %d is thinking\n", ft_time(), philo->id);
	pthread_mutex_unlock(&(philo->life->print));
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&(philo->life->print));
	if (philo->life->death == 0)
		printf(PUR "%lld %d is sleeping\n", ft_time(), philo->id);
	pthread_mutex_unlock(&(philo->life->print));
	msleep(philo->life->time_to_sleep, ft_time());
}
