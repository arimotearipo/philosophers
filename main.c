#include "philo.h"

int	m = 0;
pthread_mutex_t mutex;

void	*eat(void *a)
{
	(void)a;
	printf("Eating");
	return (0);
}

void	create_philo(t_life *life)
{
	int			i;

	life->philos = malloc(sizeof(pthread_t) * life->philo_num);
	i = 0;
	while (i < life->philo_num)
		pthread_create(&life->philos[i++], NULL, &eat, NULL);
	i = 0;
	while (i < life->philo_num)
		pthread_join(life->philos[i++], NULL);
}

int	main(int ac, char **av)
{
	t_life	life;

	life.philo_num = ft_atoi(av[1]);
	life.time_to_die = ft_atoi(av[2]);
	life.time_to_eat = ft_atoi(av[3]);
	life.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		life.eat_num = ft_atoi(av[5]);
	pthread_mutex_init(&mutex, NULL);
	create_philo(&life);
	pthread_mutex_destroy(&mutex);
	return (0);
}