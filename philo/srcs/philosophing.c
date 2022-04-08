/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:06:37 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/04 15:06:37 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Main function for the philosopher dinner.
* We assign a thread for each philosopher running the routine function.
*/

int	philosophing(t_args *args)
{
	int	i;
	t_philo	*p;

	i = 0;
	p = args->philosophers;
	args->startup_time = timer();
	while (i < args->philo_nbr)
	{
		if (pthread_create(&(p[i].thread_id), NULL, routine, &(p[i])) != 0)
		{
			printf("Error : Thread creation error\n");
			return (-1);
		}
		p[i++].last_meal = timer();
		// printf("a-last.meal : %lli\n", p[i].last_meal);
	}
	nurse(args, args->philosophers);
	thread_cleaner(args, p);
	return (0);
}

/*
* Function used by the thread of each philosopher.
* This function makes them eat through the meal function,
* and sleep or think when needed and while there is no death.
*/

void	*routine(void *temp_philosopher)
{
	int	i;
	t_args	*args;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)temp_philosopher;
	args = philo->args;
	// if (philo->philo_id % 2 != 0)
		// usleep(15000);
	while (args->death == 0)
	{
		meal(philo);
		if (args->full != 0)
			return ;
		print_action(args, philo->philo_id, "is sleeping");
		sleeping(args->time_to_sleep, args);
		print_action(args, philo->philo_id, "is thinking");
		i++;
	}
	return ;
}
