/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhiloAction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:57:05 by hapryl            #+#    #+#             */
/*   Updated: 2021/10/17 14:44:49 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isOptPhiloDead(t_philo *philo)
{
	pthread_mutex_lock(philo->stats->mutex_of_check_condition);
	if (philo->countEat >= philo->stats->arg->num_of_eat)
		philo->stats->isFinished += 1;
	pthread_mutex_unlock(philo->stats->mutex_of_check_condition);
	return (!(philo->stats->isFinished == philo->stats->arg->numberOfPhilos) && !philo->isDead);
}

int philoEat(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->mutex_of_fork);
		// taked fork
		pthread_mutex_lock(&philo->next->mutex_of_fork);
		// taked fork
	}
	else
	{
		pthread_mutex_lock(&philo->next->mutex_of_fork);
		// taked fork
		pthread_mutex_lock(&philo->mutex_of_fork);
		// taked fork
	}
	philo->eating = 1;
	philo->countEat++;
	// eating
	gettimeofday(&philo->cycle_time, NULL);
	// sleep
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex_of_fork);
	pthread_mutex_unlock(&philo->next->mutex_of_fork);
	return (0);
}

void	*philoAction(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	gettimeofday(&philo->cycle_time, NULL);
	philo->cycle_is_start = 1;
	while ((!philo->stats->arg->optional && !philo->isDead)
		|| (philo->stats->arg->optional && isOptPhiloDead(philo)))
	{
		philoEat(philo);
		philoThink(philo);
		philoSleep(philo);
	}
	return (NULL);
}
