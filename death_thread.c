/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:19:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/21 23:53:20 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_died(t_philo *philo, long long now)
{
	if ((now - philo->lastate) >= philo->life->time_to_die)
		return (1);
	return (0);
}

void	*check_death(void *grimreaper_axed)
{
	t_grimreaper	*rip;
	long long		now;

	rip = (t_grimreaper *)grimreaper_axed;
	msleep(rip->life->time_to_die);
	while (rip->life->death == 0)
	{
		now = ft_time();
		if ((now - rip->philo->lastate) > rip->life->time_to_die
				&& rip->philo->eating == 0)
		{
			printf(RED "%lld %d died\n", now, rip->philo->id);
			rip->life->death = 1;
		}
	}
	return (NULL);
}

// int	check_death(t_life *life)
// {
// 	long long	now;
// 	int			i;
	
// 	i = 0;
// 	now = ft_time();
// 	while (i < life->philo_num)
// 	{	
// 		if ((now - life->philos[i].lastate) >= life->time_to_die)
// 		{
// 			printf(RED "%lld %d died\n", now, i);
// 			life->death = 1;
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }