/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:57:22 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/24 16:05:44 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	routine(t_philo *philo)
{
	int	i;

	i = 0;
	// while (philo->life->death == 0)
	while (i < 1)
	{
		sem_wait(philo->lock);
		sem_wait(philo->nextlock);
		philo_think(philo);
		philo_takefork(philo);
		philo_takefork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		sem_post(philo->lock);
		sem_post(philo->nextlock);
		i++;
	}
}

void	set_philo(t_life *life, int i)
{
	life->philos[i].died = 0;
	life->philos[i].eaten = 0;
	life->philos[i].eating = 0;
	life->philos[i].id = i;
	life->philos[i].life = life;
	life->philos[i].lock = life->locks[i];
	life->philos[i].nextlock = life->locks[(i + 1) % 5];
}

void	create_processes(t_life *life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		if (fork() == 0)
		{
			set_philo(life, i);
			routine(&life->philos[i]);
		}
		i++;
	}
}

void	set_structs(t_life *life, int ac, char **av)
{
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	life->eat_num = -1;
	life->death = 0;
	life->philos = malloc(sizeof(t_philo) * life->philo_num);
	createforks(life);
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
}

void	createforks(t_life *life)
{
	int		i;
	char	*str;
	char	*name;

	str = "fork";
	i = 0;
	life->locks = malloc(sizeof(sem_t *) * life->philo_num);
	while (i < life->philo_num)
	{
		name = ft_strjoin(str, ft_itoa(i));
		life->locks[i] = sem_open(name, O_CREAT, 644, 1);
		free(name);
		i++;
	}
}

void	closeforks(t_life *life)
{
	int		i;

	i = 0;
	while (i < life->philo_num)
	{
		sem_close(life->locks[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_life	life;

	if (ac == 5 || ac == 6)
	{
		set_structs(&life, ac, av);
		create_processes(&life);
		closeforks(&life);
		free(life.philos);
		free(life.locks);
	}
	return (0);
}
