/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zera <zera@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:21:40 by zera              #+#    #+#             */
/*   Updated: 2021/10/16 11:02:32 by zera             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char** argv)
{
	t_args		args;
	t_stats		stats;
	t_philo		*philo;

	if (argc < 5 || argc > 6)
		return (-1);
	if (initPhilos(argv, &philo, &args, &stats))
		return(-1);
	
	return (0);
}