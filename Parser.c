/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:35 by zera              #+#    #+#             */
/*   Updated: 2021/10/16 10:53:03 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		checkArg(t_args *args)
{
	if (args->numberOfPhilos < 0 || args->timeToDie < 0 ||
		args->timeToEat < 0 || args->timeToSleep < 0 ||
		args->optional && args->num_of_eat < 0)
		return (-1);
	return (0);
}

int		parseArg(char **arg, t_args *args)
{
	args->numberOfPhilos = ft_atoi(arg[1]);
	args->timeToDie = ft_atoi(arg[2]);
	args->timeToEat = ft_atoi(arg[3]);
	args->timeToSleep = ft_atoi(arg[4]);
	if (arg[5] != NULL)	{
		args->num_of_eat = ft_atoi(arg[5]);
		args->optional = 1;
	}
	else {
		args->optional = 0;
	}
	return (checkArg(args));
}