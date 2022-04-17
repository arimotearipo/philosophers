/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:44:15 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/17 15:21:55 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*ophilo)
{
	
}

void	create_philo(t_life *life)
{
	int			i;

	life->diners = malloc(sizeof(t_philo) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
	{
		pthread_create(&(life->diners[i].philo), NULL, &routine, &(life->diners[i]));
		i++;
	}
	free(life->diners);
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
