/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:35 by zera              #+#    #+#             */
/*   Updated: 2021/10/17 12:28:17 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		negative;
	long	result;
	long	tmp;

	result = 0;
	negative = 1;
	while (*str == '\v' || *str == '\n' || *str == ' '
		|| *str == '\t' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = -1;
		str++;
	}
	while (*str >= 060 && *str <= 071)
	{
		tmp = result;
		result = (result * 10) + *str - 48;
		if (result < tmp)
			return ((negative > 0) ? -1 : 0);
		str++;
	}
	return (result * negative);
}

int	checkArg(t_args *args)
{
	if (args->numberOfPhilos < 0 || args->timeToDie < 0
		|| args->timeToEat < 0 || args->timeToSleep < 0
		|| (args->optional && args->num_of_eat < 0))
		return (-1);
	return (0);
}

int	parseArg(char **arg, t_args *args)
{
	args->numberOfPhilos = ft_atoi(arg[1]);
	args->timeToDie = ft_atoi(arg[2]);
	args->timeToEat = ft_atoi(arg[3]);
	args->timeToSleep = ft_atoi(arg[4]);
	if (arg[5] != NULL)
	{
		args->num_of_eat = ft_atoi(arg[5]);
		args->optional = 1;
	}
	else
	{
		args->optional = 0;
	}
	return (checkArg(args));
}
