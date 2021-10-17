/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:42 by zera              #+#    #+#             */
/*   Updated: 2021/10/17 13:57:59 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_args
{
	long	numberOfPhilos;
	long	timeToDie;
	long	timeToEat;
	long	timeToSleep;
	long	num_of_eat;
	int		optional;
}			t_args;

typedef struct s_stats
{
	int				isDead;
	int				isFinished;
	t_args			*arg;
	struct timeval	start_time;
	pthread_mutex_t	*mutex_of_dead;
	pthread_mutex_t	*mutex_of_message;
	pthread_mutex_t	*mutex_of_check_condition;
}					t_stats;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eating;
	int				cycle_is_start;
	int				isDead;
	long			countEat;
	struct timeval	cycle_time;
	pthread_t		thread_philo;
	pthread_t		thread_watcher;
	pthread_mutex_t	mutex_of_fork;
	t_stats			*stats;
	struct s_philo	*next;
}					t_philo;

int		parseArg(char **arg, t_args *args);
int		initPhilos(char **arg, t_philo **philo, t_args *args, t_stats *stats);
int		threadInit(t_philo *philo);
void	*philoAction(void *arg);
void	*philoActionWatcher(void *arg);

#endif
