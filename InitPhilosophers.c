/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitPhilosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:31 by zera              #+#    #+#             */
/*   Updated: 2021/10/19 22:52:04 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initStats(t_stats *stats, t_args *args)
{
	stats->arg = args;
	stats->isDead = 0;
	stats->isFinished = 0;
	stats->mutex_of_check_condition = malloc(sizeof(pthread_mutex_t));
	stats->mutex_of_dead = malloc(sizeof(pthread_mutex_t));
	stats->mutex_of_message = malloc(sizeof(pthread_mutex_t));
	if (!stats->mutex_of_dead || !stats->mutex_of_message
		|| !stats->mutex_of_check_condition)
		return (-1);
	if (pthread_mutex_init(stats->mutex_of_check_condition, NULL))
		return (-1);
	if (pthread_mutex_init(stats->mutex_of_dead, NULL))
		return (-1);
	if (pthread_mutex_init(stats->mutex_of_message, NULL))
		return (-1);
	return (0);
}

int	createPhilo(t_philo **philo, t_stats *stats, int i)
{
	(*philo) = malloc(sizeof(t_philo));
	if (!(*philo))
		return (-1);
	if (pthread_mutex_init(&(*philo)->mutex_of_fork, NULL))
		return (-1);
	(*philo)->id = i;
	(*philo)->eating = 0;
	(*philo)->cycle_is_start = 0;
	(*philo)->countEat = 0;
	(*philo)->stats = stats;
	return (0);
}

int	initPhilo(t_philo **philo, t_stats *stats)
{
	int		i;
	t_philo	*start;
	t_philo	*temp;

	i = -1;
	if (createPhilo(philo, stats, ++i))
		return (-1);
	start = (*philo);
	while (++i < stats->arg->numberOfPhilos)
	{
		if (createPhilo(&temp, stats, i))
			return (-1);
		(*philo)->next = temp;
		(*philo) = (*philo)->next;
	}
	(*philo)->next = start;
	(*philo) = start;
	return (0);
}

int	initPhilos(char **arg, t_philo **philo, t_args *args, t_stats *stats)
{
	if (parseArg(arg, args))
		return (-1);
	if (initStats(stats, args))
		return (-1);
	if (initPhilo(philo, stats))
		return (-1);
	return (0);
}
