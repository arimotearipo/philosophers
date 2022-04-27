/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:00:09 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 16:01:41 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_life	life;

	if (!errorcheck(ac, av))
		return (0);
	set_structs(&life, ac, av);
	create_processes(&life);
	end_routine(&life);
	free(life.procs);
	return (0);
}
