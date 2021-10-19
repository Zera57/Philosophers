/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:35 by zera              #+#    #+#             */
/*   Updated: 2021/10/19 22:44:51 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		negative;
	long	result;

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
		result = (result * 10) + *str - 48;
		str++;
	}
	return (result * negative);
}

unsigned long	ft_get_elapsed_time_ms(struct timeval *start_time)
{
	struct timeval	present_time;
	unsigned long	dst;

	gettimeofday(&present_time, NULL);
	dst = ((present_time.tv_sec * 1000) + (present_time.tv_usec / 1000))
		- ((start_time->tv_sec * 1000) + (start_time->tv_usec / 1000));
	return (dst);
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
	if (arg[5])
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
