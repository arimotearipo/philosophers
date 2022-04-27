/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstructs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:29:24 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:33:35 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_rules(t_life *life, int ac, char **av)
{
	life->death = 0;
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	life->eat_num = -1;
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
}

void	set_philos(t_life *life)
{
	int	i;

	life->philos = malloc(sizeof(t_philo) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
		pthread_mutex_init(&(life->philos[i++].lock), NULL);
	pthread_mutex_init(&(life->print), NULL);
	i = 0;
	while (i < life->philo_num)
	{
		life->philos[i].id = i;
		life->philos[i].eating = 0;
		life->philos[i].eaten = 0;
		life->philos[i].life = life;
		life->philos[i].nextlock
			= &(life->philos[(i + 1) % life->philo_num].lock);
		i++;
	}
}
