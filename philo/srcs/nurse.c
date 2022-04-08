/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nurse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:01:18 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/08 16:14:10 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* This function is used once all the philo threads have been launched.
* We check if any philo is dead, or if the optional argument has been met.
*/

void	nurse(t_args *a, t_philo *p)
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
				printf("timer : %lli, last.meal : %lli\n", timer(), p[i].last_meal); // soucis ici, last-meal vaut 0
				printf("time to die : %i\n", a->time_to_die);
				print_action(a, i, "died");
				a->death = 1;
			}
			pthread_mutex_unlock(&(a->eating));
			usleep(90);
		}
		if (a->death == 1)
			break ;
		i = 0;
		while (i < a->philo_nbr && p[i].fed >= a->optional && a->optional != -1)
			i++;
		if (i == a->philo_nbr)
			a->full = 1;
	}
}
