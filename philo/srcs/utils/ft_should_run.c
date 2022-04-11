/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_should_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:18:01 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/11 22:04:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	death_checker(t_args *args)
{
	pthread_mutex_lock(&(args->dead));
	if (args->death == 1)
	{
		pthread_mutex_unlock(&(args->dead));
		return (1);
	}
	pthread_mutex_unlock(&(args->dead));
	return (0);
}

int	full_checker(t_args *args)
{
	pthread_mutex_lock(&(args->mutex_full));
	if (args->full == 1)
	{
		pthread_mutex_unlock(&(args->mutex_full));
		return (1);
	}
	pthread_mutex_unlock(&(args->mutex_full));
	return (0);
}
