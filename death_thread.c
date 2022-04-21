/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:19:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/22 01:07:33 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *grimreaper_axed)
{
	t_grimreaper	*rip;
	long long		now;

	rip = (t_grimreaper *)grimreaper_axed;
	msleep(rip->life->time_to_die);
	while (rip->life->death == 0 && rip->philo->eaten != rip->life->eat_num)
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
