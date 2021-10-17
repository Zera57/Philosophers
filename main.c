/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hapryl <hapryl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:21:40 by zera              #+#    #+#             */
/*   Updated: 2021/10/17 12:31:32 by hapryl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_stats		stats;
	t_philo		*philo;

	if (argc < 5 || argc > 6)
		return (-1);
	philo = NULL;
	if (initPhilos(argv, &philo, &args, &stats))
		return (-1);
	int i = 0;
	while (i < stats.arg->numberOfPhilos)
	{
		printf("Philo id %d\n", philo->id);
		philo = philo->next;
		i++;
	}
	return (0);
}
