/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:52:11 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/04 14:52:11 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Function to get current time in milliseconds
*/

long long int	timer(void)
{
	struct timeval	tv;
	long long int	time;

	if (gettimeofday(&tv, NULL) != 0)
	{
		printf("Error : gettimeofday function failed\n");
		return (-1);
	}
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

/*
* Function to make sure uneven philosophers start their thread
* after even philosophers finished their meals.
*/

void	ft_usleep(t_args *args)
{
	while ((timer() - args->startup_time) < args->time_to_eat)
	{
		usleep(10);
	}
}

/*
* Function used to make the philosopher
* wait enough time for his current activity to end.
*/

void	waiting(long long time_to_wait, t_args *args)
{
	long long int	i;

	i = timer();
	while (death_checker(args) == 0)
	{
		if ((timer() - i) >= time_to_wait)
			return ;
		usleep(45);
	}
}
