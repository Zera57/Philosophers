/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhiloActionWatcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:01:32 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/19 13:14:57 by hapryl           ###   ########.fr       */
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
	while (1)
	{
		pthread_mutex_lock(philo->stats->mutex_of_dead);
		if (!philo->stats->isDead && philo->cycle_is_start
			&& isPhiloStarving(philo))
		{
			if (!philo->stats->isDead && !philo->stats->arg->optional)
				printDead(philo);
			philo->stats->isDead = 1;
			break ;
		}
		pthread_mutex_unlock(philo->stats->mutex_of_dead);
	}
	return (NULL);
}
