/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:23:20 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/10 20:13:41 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Once we're done, this is a cleanup function to make sure
* all the threads are done and the mutexes are destroyed
* before the program ends.
*/

void	thread_cleaner(t_args *args, t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)philo;
	while (i < args->philo_nbr)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	while (j++ < args->philo_nbr - 1)
		pthread_mutex_destroy(&(args->forks[j]));
	pthread_mutex_destroy(&(args->eating));
	pthread_mutex_destroy(&(args->printing));
}
