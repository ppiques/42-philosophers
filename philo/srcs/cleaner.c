/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:23:20 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/04 16:23:20 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* This function is used once all the philo threads have been launched.
* We check if any philo is dead, or if the optional argument has been met.
*/

void	check_death(t_args *a, t_philo *p)
{
	int	i;

	while (a->full == 0)
	{
		i = 0;
		while (i++ < a->philo_nbr && a->death == 0)
		{
			pthread_mutex_lock(&(a->eating));
			if ((timer() - p[i].last_meal) > a->time_to_die)
			{
				print_action(a, i, "died");
				a->death = 1;
			}
			pthread_mutex_unlock(&(a->eating));
			usleep(90);
		}
		if (a->death == 1)
			break ;
		i = 0;
		while (a->optional != -1 && i < a->philo_nbr && p[i].fed >= a->optional)
			i++;
		if (i == a->philo_nbr)
			a->full = 1;
	}
}

/*
* Once we're done, this is a cleanup function to make sure 
* all the threads are done and the mutexes are destroyed before the program ends.
*/

void	thread_cleaner(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	while (i++ < args->philo_nbr)
		pthread_join(philo[i].thread_id, NULL);
	i = 0;
	while (i++ < args->philo_nbr)
		pthread_mutex_destroy(&(args->forks[i]));
	pthread_mutex_destroy(&(args->printing));
}