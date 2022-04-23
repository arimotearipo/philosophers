/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/22 12:35:20 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_life	*life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_join(life->philos[i].thread, NULL);
		pthread_join(life->philos[i].reaper, NULL);
		i++;
	}
}

void	create_threads(t_life *life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_create(&(life->philos[i].thread),
			NULL, &routine, &(life->philos[i]));
		pthread_create(&(life->philos[i].reaper),
			NULL, &check_death, &(life->philos[i]));
		i++;
	}
}

void	destroy_mutex(t_life *life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_mutex_destroy(&(life->philos[i].lock));
		i++;
	}
}

int	main(int ac, char **av)
{
	t_life	life;

	if (ac == 5 || ac == 6)
	{
		set_rules(&life, ac, av);
		set_philos(&life);
		create_threads(&life);
		join_threads(&life);
		destroy_mutex(&life);
		free(life.philos);
		return (0);
	}
	return (0);
}
