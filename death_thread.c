/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:19:30 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/19 20:58:51 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_death(void *life_axed)
{
	t_life		*life;
	long long	now;
	int			i;

	life = (t_life *)life_axed;
	i = 0;
	while (1)
	{
		now = ft_time();
		while (i < life->philo_num)
		{
			if ((now - life->philos[i].lastate) >= life->time_to_die)
			{
				printf(RED "%lld %d died\n", now, i);
				return (NULL);
			}
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
// 		// printf("entered\n");
// 		printf("%lld - %lld = %lld\n", now, life->philos[i].lastate, now - life->philos[i].lastate);
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