/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:57:22 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:12:10 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death(void *life_axed)
{
	t_life		*life;
	long long	now;

	life = (t_life *)life_axed;
	msleep(life->time_to_die, ft_time());
	while (life->death == 0 && life->eaten != life->eat_num)
	{
		now = ft_time();
		if ((now - life->lastate) > life->time_to_die
			&& life->eating == 0)
		{
			sem_wait(life->print);
			printf(RED "%lld %d died\n", now, life->id);
			life->death = 1;
		}
	}
	if (life->death == 1)
		exit(1);
	exit(0);
	return (NULL);
}

int	routine(t_life *life)
{
	int	i;

	i = 0;
	pthread_create(&(life->reaper), NULL, &death, life);
	if (life->id % 2 == 0)
		usleep(1000);
	while (life->death == 0)
	{
		philo_think(life);
		sem_wait(life->locks);
		philo_takefork(life);
		sem_wait(life->locks);
		philo_takefork(life);
		philo_eat(life);
		sem_post(life->locks);
		sem_post(life->locks);
		philo_sleep(life);
		i++;
	}
	pthread_join(life->reaper, NULL);
	exit (0);
}

void	create_processes(t_life *life)
{
	int		i;

	i = 0;
	while (i < life->philo_num)
	{
		life->procs[i] = fork();
		if (life->procs[i] == 0)
		{
			life->id = i;
			routine(life);
		}
		i++;
	}
}

void	end_routine(t_life *life)
{
	int	i;
	int	status;

	i = 0;
	while (i < life->philo_num)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < life->philo_num)
				kill(life->procs[i++], SIGKILL);
			break ;
		}
		i++;
	}
	sem_close(life->locks);
	sem_close(life->print);
	sem_unlink("/fork");
	sem_unlink("/print");
}

void	set_structs(t_life *life, int ac, char **av)
{
	life->philo_num = ft_atoi(av[1]);
	life->time_to_die = ft_atoi(av[2]);
	life->time_to_eat = ft_atoi(av[3]);
	life->time_to_sleep = ft_atoi(av[4]);
	life->eat_num = -1;
	life->id = -1;
	life->death = 0;
	life->eaten = 0;
	life->eating = 0;
	life->procs = malloc(sizeof(pid_t *) * life->philo_num);
	sem_unlink("/fork");
	sem_unlink("/print");
	life->locks = sem_open("/fork", O_CREAT, 0644, life->philo_num);
	life->print = sem_open("/print", O_CREAT, 0644, 1);
	if (ac == 6)
		life->eat_num = ft_atoi(av[5]);
}
