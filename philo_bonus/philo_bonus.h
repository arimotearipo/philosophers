/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:00 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:11:56 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <signal.h>
# include <pthread.h>
# include <limits.h>
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
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

typedef struct s_life
{
	int			id;
	long long	lastate;
	int			eaten;
	int			eating;
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_num;
	int			death;
	pthread_t	reaper;
	pid_t		*procs;
	sem_t		*locks;
	sem_t		*print;
}	t_life;

int			errorcheck(int ac, char **av);
long		ft_atoi(const char *s);
char		*ft_itoa(int n);
long long	ft_time(void);
void		msleep(int n, long long start);
void		set_structs(t_life *life, int ac, char **av);
void		create_processes(t_life *life);
void		end_routine(t_life *life);
void		philo_sleep(t_life *life);
void		philo_think(t_life *life);
void		philo_eat(t_life *life);
void		philo_takefork(t_life *life);
char		*ft_strjoin(char const *s1, char const *s2);

#endif