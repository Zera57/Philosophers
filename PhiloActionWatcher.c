/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhiloActionWatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:01:32 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/25 23:39:29 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isPhiloStarving(t_philo *philo)
{
	return (!philo->eating
		&& ((ft_get_elapsed_time_ms(&philo->cycle_time))
			> (unsigned long) philo->stats->arg->timeToDie));
}

void	*philoActionWatcher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo == philo->next)
	{
		threadSleep(((unsigned long) philo->stats->arg->timeToDie
				- ft_get_elapsed_time_ms(&philo->cycle_time)) * 1000);
		printDead(philo);
		return (NULL);
	}
	while (1)
	{
		pthread_mutex_lock(philo->stats->mutex_of_dead);
		if (!philo->stats->isDead && philo->cycle_is_start
			&& isPhiloStarving(philo))
		{
			if (!philo->stats->isDead && philo->stats->isFinished
				!= philo->stats->arg->numberOfPhilos)
				printDead(philo);
			philo->stats->isDead = 1;
			break ;
		}
		pthread_mutex_unlock(philo->stats->mutex_of_dead);
	}
	return (NULL);
}
