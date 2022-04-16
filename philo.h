#ifndef PHILO_H
# define PHILO_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef	struct	s_life
{
	pthread_t	*philos;
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_num;
}				t_life;

#endif
