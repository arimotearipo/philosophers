/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setphilo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:27:20 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/18 10:45:26 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*ophilo)
{
	t_philo	*philo;

	philo = (t_philo*)ophilo;
	return (NULL);
}

void	create_philo(t_life *life)
{
	int			i;
	int			*random;

	life->philos = malloc(sizeof(t_philo) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
	{
		pthread_create(&(life->philos[i].person),
			NULL, &routine, &(life));
		i++;
	}
	i = 0;
	while (i < life->philo_num)
	{
		life->philos[i].fork_id = i;
		life->philos[i].person_id = i;
		life->philos[i].nextfork_id = (i + 1) % life->philo_num;
		life->philos[i].times_ate = 0;
		i++;
	}
	free(life->philos);
}

void	setlife(t_life *life, int ac, char **av)
{
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
	create_philo(life);
}
