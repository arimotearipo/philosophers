/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:11:21 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:11:48 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_takefork(t_life *life)
{
	long long	time;

	time = ft_time();
	sem_wait(life->print);
	printf(BLU "%lld %d has taken a fork\n", time, life->id);
	sem_post(life->print);
}

void	philo_eat(t_life *life)
{
	long long	time;

	if (life->death == 1)
		return ;
	time = ft_time();
	life->eating = 1;
	life->lastate = time;
	sem_wait(life->print);
	printf(YEL "%lld %d is eating\n", time, life->id);
	sem_post(life->print);
	msleep(life->time_to_eat, time);
	life->eaten += 1;
	life->eating = 0;
}

void	philo_think(t_life *life)
{
	if (life->death == 1)
		return ;
	sem_wait(life->print);
	printf(WHT "%lld %d is thinking\n", ft_time(), life->id);
	sem_post(life->print);
}

void	philo_sleep(t_life *life)
{
	if (life->death == 1)
		return ;
	sem_wait(life->print);
	printf(PUR "%lld %d is sleeping\n", ft_time(), life->id);
	sem_post(life->print);
	msleep(life->time_to_sleep, ft_time());
}
