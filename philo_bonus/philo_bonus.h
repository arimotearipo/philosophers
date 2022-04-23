#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
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

typedef struct s_philo
{
	long long		lastate;
	int				eaten;
	int				died;
	int				eating;
	int				id;
	sem_t			lock;
	sem_t			nextlock;
	struct s_life	*life;
}	t_philo;

typedef struct s_life
{
	int		philo_num;
	int		time_to_die;
	int 	time_to_eat;
	int 	time_to_sleep;
	int		eat_num;
	int		death;
	t_philo	*philos;
	sem_t	**locks;
}	t_life;

int			ft_atoi(const char *s);
char		*ft_itoa(int n);
long long	ft_time(void);
void		msleep(int n);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_takefork(t_philo *philo);
char		*ft_strjoin(char const *s1, char const *s2);

#endif