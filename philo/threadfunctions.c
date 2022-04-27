/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadfunctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:19:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:37:01 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *philo_axed)
{
	t_philo			*philo;
	long long		now;

	philo = (t_philo *)philo_axed;
	msleep(philo->life->time_to_die, ft_time());
	while (philo->life->death == 0 && philo->eaten != philo->life->eat_num)
	{
		now = ft_time();
		if ((now - philo->lastate) > philo->life->time_to_die
			&& philo->eating == 0)
		{
			printf(RED "%lld %d died\n", now, philo->id);
			philo->life->death = 1;
		}
	}
	return (NULL);
}

void	*routine(void	*philo_axed)
{
	t_philo		*philo;

	philo = (t_philo *)philo_axed;
	while (philo->life->death == 0 && philo->eaten != philo->life->eat_num)
	{	
		philo_think(philo);
		if (philo->id % 2 != 0 && philo->eaten == 0)
			usleep(philo->life->philo_num * 100);
		pthread_mutex_lock(&(philo->lock));
		philo_takefork(philo);
		if (philo->nextlock == &(philo->lock))
			break ;
		pthread_mutex_lock(philo->nextlock);
		philo_takefork(philo);
		philo_eat(philo);
		pthread_mutex_unlock(&(philo->lock));
		pthread_mutex_unlock(philo->nextlock);
		philo_sleep(philo);
	}
	return (NULL);
}
