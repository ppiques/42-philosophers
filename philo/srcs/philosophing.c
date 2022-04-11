/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:06:37 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/10 20:13:05 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Main function for the philosopher dinner.
* We assign a thread for each philosopher running the routine function.
*/

int	philosophing(t_args *args)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = args->philosophers;
	args->startup_time = timer();
	while (i < args->philo_nbr)
	{
		p[i].last_meal = timer();
		if (pthread_create(&(p[i].thread_id), NULL, routine, &(p[i])) != 0)
		{
			printf("Error : Thread creation error\n");
			thread_cleaner(args, p);
			return (-1);
		}
		i++;
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
	t_args	*args;
	t_philo	*philo;

	philo = (t_philo *)temp_philosopher;
	args = philo->args;
	if (philo->philo_id % 2 != 0)
		ft_usleep(args);
	while (death_checker(args) == 0)
	{
		meal(philo);
		pthread_mutex_lock(&(args->eating));
		philo->fed++;
		pthread_mutex_unlock(&(args->eating));
		if (full_checker(args) == 1)
			return (NULL);
		post_meal(args, philo);
	}
	return (NULL);
}

/*
* This function is for the edge case of a lone philosopher.
* We only create a single thread using the alone function.
*/

int	lone_dinner(t_args *args)
{
	t_philo	*philo;

	philo = args->philosophers;
	args->startup_time = timer();
	if (pthread_create(&(philo[0].thread_id), NULL, alone, &(philo[0])) != 0)
	{
		printf("Error : Thread creation error\n");
		thread_cleaner(args, philo);
		return (-1);
	}
	thread_cleaner(args, philo);
	return (0);
}

/*
* This is the function for the lone philosopher thread. As he is alone,
* there is only one fork. As such, he can't eat, and dies once the time_to_die
* has been reached.
*/

void	*alone(void *temp_philosopher)
{
	t_args	*args;
	t_philo	*philo;

	philo = (t_philo *)temp_philosopher;
	args = philo->args;
	while (1)
	{
		if ((timer() - args->startup_time) > args->time_to_die)
		{
			print_action(args, philo[0].philo_id, "died");
			return (NULL);
		}
	}
	return (NULL);
}
