/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:34:06 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/19 22:48:56 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	threadSleep(unsigned long time)
{
	struct timeval	start_sleep;

	time = time / 1000;
	gettimeofday(&start_sleep, NULL);
	while (ft_get_elapsed_time_ms(&start_sleep) < time)
		usleep(10);
}

int	createThreads(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->stats->arg->numberOfPhilos)
	{
		pthread_create(&philo->thread_philo,
			NULL,
			philoAction,
			(void *)philo);
		pthread_create(&philo->thread_watcher,
			NULL,
			philoActionWatcher,
			(void *)philo);
		philo = philo->next;
	}
	return (0);
}

int	threadsInit(t_philo *philo)
{
	int	i;

	gettimeofday(&philo->stats->start_time, NULL);
	createThreads(philo);
	i = -1;
	while (++i < philo->stats->arg->numberOfPhilos)
	{
		pthread_join(philo->thread_philo, NULL);
		philo = philo->next;
	}
	return (0);
}
