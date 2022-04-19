/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:19:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/19 20:00:11 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*check_death(void *life_axed)
// {
// 	t_life		*life;
// 	long long	time;
// 	int			i;

// 	life = (t_life *)life_axed;
// 	i = 0;
// 	while (1)
// 	{
// 		time = ft_time();
// 		while (i < life->philo_num)
// 		{
// 			if ((time - life->philos[i].lastate) >= life->time_to_die)
// 			{
// 				printf(RED "%lld %d died\n", time, i);
// 				exit(0);
// 			}
// 		}
// 	}
// 	return (NULL);
// }

void	check_death(t_life *life)
{
	long long	now;
	int			i;
	
	i = 0;
	now = ft_time();
	while (i < life->philo_num)
	{	
		if ((now - life->philos[i].lastate) >= life->time_to_die)
		{
			printf(RED "%lld %d died\n", now, i);
			exit(0);
		}
		i++;
	}
}