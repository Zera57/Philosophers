/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhiloAction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:57:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/25 14:49:02 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isOptPhiloDead(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_check_condition);
	if (philo->countEat >= philo->stats->arg->num_of_eat)
		philo->stats->isFinished += 1;
	pthread_mutex_unlock(philo->stats->mutex_of_check_condition);
	return (!(philo->stats->isFinished == philo->stats->arg->numberOfPhilos)
		 && !philo->stats->isDead);
}

void	*soloPhilo(t_philo *philo)
{
	printTakeFork(philo);
	threadSleep(philo->stats->arg->timeToDie * 1000);
	return (NULL);
}

int	philoEat(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->mutex_of_fork);
		printTakeFork(philo);
		pthread_mutex_lock(&philo->next->mutex_of_fork);
		printTakeFork(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->next->mutex_of_fork);
		printTakeFork(philo);
		pthread_mutex_lock(&philo->mutex_of_fork);
		printTakeFork(philo);
	}
	philo->eating = 1;
	philo->countEat++;
	printEating(philo);
	gettimeofday(&philo->cycle_time, NULL);
	threadSleep(philo->stats->arg->timeToEat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex_of_fork);
	pthread_mutex_unlock(&philo->next->mutex_of_fork);
	return (0);
}

int	philoSleep(t_philo *philo)
{
	printSleeping(philo);
	threadSleep(philo->stats->arg->timeToSleep * 1000);
	return (0);
}

void	*philoAction(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->cycle_time, NULL);
	philo->cycle_is_start = 1;
	if (philo == philo->next)
	{
		return (soloPhilo(philo));
	}
	while ((!philo->stats->arg->optional && !philo->stats->isDead)
		|| (philo->stats->arg->optional && isOptPhiloDead(philo)))
	{
		philoEat(philo);
		philoSleep(philo);
		printThinking(philo);
	}
	return (NULL);
}
