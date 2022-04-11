/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:36:02 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/01 12:36:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Function to print what the philosopher is doing,
* mutex lock to make sure the variables don't change
*/

void	print_action(t_args *args, int id, char *action)
{
	long long int	time;

	pthread_mutex_lock(&(args->printing));
	if (death_checker(args) == 1)
	{
		pthread_mutex_unlock(&(args->printing));
		return ;
	}
	time = timer() - args->startup_time;
	printf("%lli %d %s\n", time, id, action);
	pthread_mutex_unlock(&(args->printing));
	return ;
}

/*
* This is the eating function.
* We lock the mutexes of the forks next to the philosopher
* and unlock them when he is done.
* Timing makes the philosopher finish his meal before.
* We also keep track of how many times
* each philosopher has eaten with the philo->fed variable.
*/

void	meal(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	if (death_checker(args) == 0)
	{
		pthread_mutex_lock(&(args->forks[philo->left_fork]));
		print_action(args, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(args->forks[philo->right_fork]));
		print_action(args, philo->philo_id, "has taken a fork");
		pthread_mutex_lock(&(args->eating));
		print_action(args, philo->philo_id, "is eating");
		philo->last_meal = timer();
		pthread_mutex_unlock(&(args->eating));
		waiting(args->time_to_eat, args);
		pthread_mutex_unlock(&(args->forks[philo->left_fork]));
		pthread_mutex_unlock(&(args->forks[philo->right_fork]));
	}
}

/*
* Function called right after the meal function is done.
* The philosopher sleeps, then think until it is time to eat again.
*/

void	post_meal(t_args *args, t_philo *philo)
{
	if (death_checker(args) == 0)
	{
		print_action(args, philo->philo_id, "is sleeping");
		waiting(args->time_to_sleep, args);
		print_action(args, philo->philo_id, "is thinking");
	}
}
