/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/21 23:58:48 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*philo_axed)
{
	t_philo		*philo;

	philo = (t_philo *)philo_axed;
	while (philo->life->death == 0)
	{	
		philo_think(philo);
		if (philo->id % 2 == 0)
			usleep(200);
		pthread_mutex_lock(&(philo->lock));
		pthread_mutex_lock(philo->nextlock);
		printf(BLU "%lld %d has taken a fork\n", ft_time(), philo->id);
		printf(BLU "%lld %d has taken a fork\n", ft_time(), philo->id);
		philo_eat(philo);
		pthread_mutex_unlock(&(philo->lock));
		pthread_mutex_unlock(philo->nextlock);
		philo_sleep(philo);
		printf(GRN "VALUE OF DEATH: %d\n", philo->life->death);
	}
	return (NULL);
}

void	join_threads(t_life	*life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_join(life->philos[i].thread, NULL);
		pthread_join(life->rip[i].reaper, NULL);
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
		pthread_create(&(life->rip[i].reaper),
			NULL, &check_death, &(life->rip[i]));
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
		set_grimreaper(&life);
		create_threads(&life);
		join_threads(&life);
		destroy_mutex(&life);
		free(life.philos);
		free(life.rip);
		return (0);
	}
	printf("./philo philo_num time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
	// system("leaks philo");
	return (0);
}
