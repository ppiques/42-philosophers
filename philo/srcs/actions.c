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

	time = timer() - args->startup_time;
	pthread_mutex_lock(&(args->printing));
	printf("%lli %d %s\n", time, id, action);
	pthread_mutex_unlock(&(args->printing));
	return ;
}

/*
* Function to make the philosopher sleep. 
* We make a quick operation to make sure the philosopher is sleeping enough,
* depending on the args given.
*/

void	sleeping(long long time_to_sleep, t_args *args)
{
	long long int	i;

	i = timer();
	while (args->death == 0)
	{
		if ((i - timer()) >=  time_to_sleep)
			break;
		usleep(45);
	}
}

/*
* Function called after the philosopher has eaten. The philosopher thinks as much as he eats.
*/

void	thinking(long long time_to_think, t_args *args)
{
	long long int	i;

	i = timer();
	while (args->death == 0)
	{
		if ((i - timer()) >=  time_to_think)
			break;
		usleep(45);
	}
}

/*
* This is the eating function. We lock the mutexes of the forks next to the philosopher
* and unlock them when he is done. Note that thinking is called here after the philosopher has eaten.
* We also keep track of how many times each philosopher has eaten with the philo->fed variable.
*/

void	meal(t_philo *philo)
{
	t_args	*args;

	args = philo->args;
	pthread_mutex_lock(&(args->forks[philo->right_fork]));
	print_action(args, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(args->forks[philo->left_fork]));
	print_action(args, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(args->eating));
	print_action(args, philo->philo_id, "is eating");
	philo->last_meal = timer();
	pthread_mutex_unlock(&(args->eating));
	thinking(args->time_to_eat, args);
	(philo->fed)++;
	pthread_mutex_unlock(&(args->forks[philo->right_fork]));
	pthread_mutex_unlock(&(args->forks[philo->left_fork]));
}


