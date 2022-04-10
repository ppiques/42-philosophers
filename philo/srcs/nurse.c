/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nurse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:01:18 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/09 16:07:27 by ppiques          ###   ########.fr       */
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
			{
				print_action(args, i, "died");
				args->death = 1;
			}
			pthread_mutex_unlock(&(args->eating));
			usleep(90);
			i++;
		}
		if (args->death == 1)
			return ;
		i = 0;
		while (i < args->philo_nbr && philo[i].fed >= args->optional)
			i++;
		if (i == args->philo_nbr && args->optional != -1)
			args->full = 1;
	}
}
