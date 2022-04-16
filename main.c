/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/16 19:06:16 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*eat(void	*ophilo)
{
	t_philo	*nphilo;

	nphilo = ophilo;
	pthread_mutex_lock(&nphilo->fork);
	printf("Eating\n");
	sleep(3);
	printf("Done eating!\n");
	pthread_mutex_unlock(&nphilo->fork);
	return (0);
}

void	create_philo(t_life *life)
{
	int			i;

	life->philos = malloc(sizeof(t_philo) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
		pthread_mutex_init(&life->philos[i++].fork, NULL);
	i = 0;
	while (i < life->philo_num)
	{
		pthread_create(&life->philos[i].person, NULL, &eat, &life->philos[i]);
		i++;
	}
	i = 0;
	while (i < life->philo_num)
		pthread_join(life->philos[i++].person, NULL);
	i = 0;
	while (i < life->philo_num)
		pthread_mutex_destroy(&life->philos[i++].fork);
	free(life->philos);
}

void	initialize(t_life *life, int	ac, char **av)
{
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
	create_philo(life);
}

int	main(int ac, char **av)
{
	t_life	life;
	if (ac == 5 || ac == 6)
		initialize(&life, ac, av);
	system("leaks philo");
	return (0);
}
