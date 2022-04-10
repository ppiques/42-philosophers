/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:22:29 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/09 11:31:03 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* This function initializes the rules of the program based on the arguments given
*/

int	global_args_init(const char **argv, t_args *args)
{
	args->philo_nbr = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->optional = ft_atoi(argv[5]);
	else
		args->optional = -1;
	args->death = 0;
	args->full = 0;
	if (check_global_args(args) == -1)
		return (-1);
	mutex_init(args);
	philosophers_init(args);
	return (0);
}

/*
* This function initializes the mutexes used in the args structure
*/

int	mutex_init(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->philo_nbr)
		args->forks[i++] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	args->eating = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	args->printing = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (0);
}

/*
* This function initializes each individual philosopher
*/

int	philosophers_init(t_args *args)
{
	int	i;

	i = args->philo_nbr - 1;
	while (i >= 0)
	{
		args->philosophers[i].args = args;
		args->philosophers[i].philo_id = i + 1;
		args->philosophers[i].right_fork = (i + 1) % args->philo_nbr;
		args->philosophers[i].left_fork = i;
		args->philosophers[i].fed = 0;
		args->philosophers[i].last_meal = 0;
		i--;
	}
	return (0);
}

/*
* This function checks that the arguments given are actually usable
* Please note that the program has a limit of 200 philosophers
*/

int	check_global_args(t_args *args)
{
	if (args->philo_nbr <= 0 || args->time_to_die < 0
		|| args->time_to_eat < 0 || args->time_to_sleep < 0
		|| args->optional == 0 || args->philo_nbr > 200)
	{
		printf("Error : Invalid arguments\n");
		return (-1);
	}
	return (0);
}
