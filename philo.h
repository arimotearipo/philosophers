/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:43:55 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/18 10:26:09 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		person;
	int				person_id;
	int				fork_id;
	int				nextfork_id;
	int				fork_avalaible;
	int				times_ate;
	struct timeval	last_ate;
}				t_philo;

typedef struct s_life
{
	t_philo			*philos;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_num;
	pthread_mutex_t	eat;
	struct timeval	starttime;
}				t_life;

int	ft_atoi(const char *s);

#endif
