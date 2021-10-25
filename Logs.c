/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:58:35 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/25 17:11:55 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printDead(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_message);
	if (!philo->stats->isDead)
	{
		printf("%lu ms %d died\n",
			ft_get_elapsed_time_ms(&philo->stats->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->stats->mutex_of_message);
}

void	printEating(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_message);
	if (!philo->stats->isDead)
	{
		printf("%lu ms %d is eating\n",
			ft_get_elapsed_time_ms(&philo->stats->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->stats->mutex_of_message);
}

void	printSleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_message);
	if (!philo->stats->isDead)
	{
		printf("%lu ms %d is sleeping\n",
			ft_get_elapsed_time_ms(&philo->stats->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->stats->mutex_of_message);
}

void	printThinking(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_message);
	if (!philo->stats->isDead)
	{
		printf("%lu ms %d is thinking\n",
			ft_get_elapsed_time_ms(&philo->stats->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->stats->mutex_of_message);
}

void	printTakeFork(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_message);
	if (!philo->stats->isDead)
	{
		printf("%lu ms %d has taken a fork\n",
			ft_get_elapsed_time_ms(&philo->stats->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->stats->mutex_of_message);
}
