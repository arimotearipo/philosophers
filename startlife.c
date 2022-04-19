/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startlife.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:05:46 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/18 15:51:09 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*context)
{
	(void)context;
	return (NULL);
}

void	startlife(t_life *life)
{
	int	i;

	i = 0;
	while (i < life->philo_num)
	{
		pthread_join(life->philos[i].th, NULL);
		i++;
	}
}
