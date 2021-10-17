/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:34:06 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/17 13:06:11 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int createThreads(t_philo *philo)
{
	int i;

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

int	threadInit(t_philo *philo)
{
	int i;

	createThreads(philo);
	i = -1;
	while (++i < philo->stats->arg->numberOfPhilos)
	{
		pthread_join(philo->thread_philo, NULL);
		philo = philo->next;
	}
	return (0);
}