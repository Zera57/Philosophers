/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitPhilosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:31 by zera              #+#    #+#             */
/*   Updated: 2021/10/17 12:25:32 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initStats(t_stats *stats, t_args *args)
{
	stats->arg = args;
	stats->is_dead = 0;
	stats->is_finished = 0;
	gettimeofday(&stats->start_time, NULL);
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

int	initPhilo(t_philo **philo, t_stats *stats)
{
	int		i;
	t_philo	*start;
	t_philo	*temp;

	i = -1;
	while (++i < stats->arg->numberOfPhilos)
	{
		temp = malloc(sizeof(t_philo));
		if (!temp)
			return (-1);
		temp->id = i;
		temp->eating = 0;
		temp->cycle_is_start = 0;
		temp->stats = stats;
		if (pthread_mutex_init(&temp->mutex_of_fork, NULL))
			return (-1);
		if (*philo)
		{
			(*philo)->next = temp;
			(*philo) = (*philo)->next;
		}
		else
		{
			(*philo) = temp;
			start = (*philo);
		}
	}
	(*philo)->next = start;
	(*philo) = start;
	printf("Num of filos %d\n", i + 1);
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
