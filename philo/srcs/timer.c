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

long long int   timer(void)
{
    struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
	{
		printf("Error : gettimeofday function failed\n");
		return (-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}