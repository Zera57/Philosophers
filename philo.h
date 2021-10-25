/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:09:42 by zera              #+#    #+#             */
/*   Updated: 2021/10/25 23:35:54 by zera             ###   ########.fr       */
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
	long			countEat;
	struct timeval	cycle_time;
	pthread_t		thread_philo;
	pthread_t		thread_watcher;
	pthread_mutex_t	mutex_of_fork;
	t_stats			*stats;
	struct s_philo	*next;
}					t_philo;

int				parseArg(char **arg, t_args *args);
int				initPhilos(char **arg, t_philo **philo,
					t_args *args, t_stats *stats);
void			*philoAction(void *arg);
void			*philoActionWatcher(void *arg);
int				isOptPhiloDead(t_philo *philo);
unsigned long	ft_get_elapsed_time_ms(struct timeval *start_time);

void			printDead(t_philo *philo);
void			printEating(t_philo *philo);
void			printSleeping(t_philo *philo);
void			printThinking(t_philo *philo);
void			printTakeFork(t_philo *philo);

int				threadsInit(t_philo *philo);
void			threadSleep(unsigned long time);

#endif
