/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/19 19:59:56 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*function(void	*philo_axed)
{
	t_philo		*philo;
	// int		i;

	philo = (t_philo *)philo_axed;
	// pthread_mutex_lock(&life->varlock);
	// i = life->philoptr++;
	// pthread_mutex_unlock(&life->varlock);
	philo_think(philo);
	pthread_mutex_lock(&(philo->lock));
	pthread_mutex_lock(philo->nextlock);
	printf(BLU "%lld %d has taken a fork\n", ft_time(), philo->id);
	printf(BLU "%lld %d has taken a fork\n", ft_time(), philo->id);
	philo_eat(philo);
	pthread_mutex_unlock(&(philo->lock));
	pthread_mutex_unlock(philo->nextlock);
	philo_sleep(philo);
	return (NULL);
}

void	join_threads(t_life	*life)
{
	int	i;

	i = 0;
	// pthread_join(life->deaththread, NULL);
	while (i < life->philo_num)
	{
		pthread_join(life->philos[i].thread, NULL);
		i++;
	}
}

void	create_threads(t_life *life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_create(&(life->philos[i].thread), NULL, &function, &(life->philos[i]));
		i++;
	}
	i = 0;
	while (i < life->philo_num)
	{
		pthread_join(life->philos[i].thread, NULL);
		i++;
	}
	// pthread_create(&(life->deaththread), NULL, &check_death, life);
	// pthread_join(life->deaththread, NULL);
}

void	set_rules(t_life *life, int	ac, char **av)
{
	int	i;

	// life->philoptr = 0;
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	life->eat_num = -1;
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
	life->philos = malloc(sizeof(t_philo*) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
	{
		pthread_mutex_init(&(life->philos[i].lock), NULL);
		i++;
	}
	i = 0;
	while (i < life->philo_num)
	{
		life->philos[i].id = i;
		life->philos[i].dead = 0;
		life->philos[i].eaten = 0;
		life->philos[i].life = life;
		life->philos[i].nextlock = &(life->philos[(i + 1) % life->philo_num].lock);
		i++;
	}
}

void	destroy_mutex(t_life	*life)
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
		create_threads(&life);
		join_threads(&life);
		while (1)
			check_death(&life);
		destroy_mutex(&life);
		return (0);
	}
	printf("./philo philo_num time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
	// system("leaks philo");
	return (0);
}
