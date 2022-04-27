/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:08:20 by wwan-taj          #+#    #+#             */
/*   Updated: 2022/04/27 11:57:26 by wwan-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	checkinputnumber(int ac, char **av)
{
	(void)av;
	if (ac != 4 && ac != 5)
	{
		printf("Error: Needs to be 4 or 5 inputs\n");
		return (0);
	}
	return (1);
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

static int	checkdigit(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("Error: Needs to be numerical value\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	checkvalue(int ac, char **av)
{
	int		i;
	long	input;

	i = 1;
	while (i < ac)
	{
		input = ft_atoi(av[i]);
		if (input < 0)
		{
			printf("Error: Must be positive numbers\n");
			return (0);
		}
		else if (input > INT_MAX)
		{
			printf("Error: Input exceeds max int value\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	errorcheck(int ac, char **av)
{
	if (!checkinputnumber(ac, av))
		return (0);
	if (!checkvalue(ac, av))
		return (0);
	if (!checkdigit(ac, av))
		return (0);
	return (1);
}
