/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:31:25 by wwan-taj         ###   ########.fr       */
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
	pthread_mutex_destroy(&(life->print));
}

int	main(int ac, char **av)
{
	t_life	life;

	if (!errorcheck(ac, av))
		return (0);
	set_rules(&life, ac, av);
	set_philos(&life);
	create_threads(&life);
	join_threads(&life);
	destroy_mutex(&life);
	free(life.philos);
	return (0);
}
