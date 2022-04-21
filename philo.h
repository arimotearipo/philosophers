/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:43:55 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/21 23:51:42 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define BLK "\033[0;30m"
# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YEL "\033[0;33m"
# define MAG "\e[0;35m"
# define BLU "\033[0;34m"
# define PUR "\033[0;35m"
# define CYN "\033[0;36m"
# define WHT "\e[0;37m"

typedef struct s_grimreaper
{
	pthread_t		reaper;
	struct s_life	*life;
	struct s_philo	*philo;
}				t_grimreaper;

typedef struct s_philo
{
	int				id;
	long long		starttime;
	long long		lastate;
	int				eating;
	int				dead;
	int				eaten;
	struct s_life	*life;
	pthread_t		thread;
	pthread_mutex_t	lock;
	pthread_mutex_t	*nextlock;
}				t_philo;

typedef struct s_life
{
	t_philo			*philos;
	t_grimreaper	*rip;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	int				death;
}				t_life;

int			ft_atoi(const char *s);
long long	ft_time(void);
void		msleep(int n);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		set_rules(t_life *life, int	ac, char **av);
void		set_philos(t_life *life);
void		set_grimreaper(t_life *life);
void		*check_death(void *life_axed);
// int			check_death(t_life *life);

#endif
