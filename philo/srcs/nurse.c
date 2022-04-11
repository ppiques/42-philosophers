/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nurse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:01:18 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/11 22:53:30 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* This function is used once all the philo threads have been launched.
* We check if any philo is dead, or if the optional argument has been met.
*/

void	nurse(t_args *args, t_philo *philo)
{
	int	i;

	while (args->full == 0)
	{
		i = 0;
		while (i < args->philo_nbr && args->death == 0)
		{
			pthread_mutex_lock(&(args->eating));
			if ((timer() - philo[i].last_meal) > args->time_to_die)
				nurse_funeral(args, &(philo[i]));
			pthread_mutex_unlock(&(args->eating));
			i++;
		}
		if (args->death == 1)
			return ;
		i = 0;
		pthread_mutex_lock(&(args->eating));
		while (i < args->philo_nbr && philo[i].fed >= args->optional)
			i++;
		pthread_mutex_unlock(&(args->eating));
		pthread_mutex_lock(&(args->mutex_full));
		if (i == args->philo_nbr && args->optional != -1)
			args->full = 1;
		pthread_mutex_unlock(&(args->mutex_full));
	}
}

void	nurse_funeral(t_args *args, t_philo *philo)
{
	long long int	time;

	pthread_mutex_lock(&(args->dead));
	args->death = 1;
	pthread_mutex_unlock(&(args->dead));
	time = timer() - args->startup_time;
	pthread_mutex_lock(&(args->printing));
	printf("%lli %d died\n", time, philo->philo_id);
	pthread_mutex_unlock(&(args->printing));
	return ;
}
