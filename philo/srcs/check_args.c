/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:39:28 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/21 10:39:28 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
* Function to check if there are enough arguments and if they are actually numbers
*/

int	check_args(int argc, const char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((argc < 5) || (argc > 6))
	{
		printf("Error : Invalid number of arguments\n");
		return (1);
	}
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 1)
			{
				printf("Error : Invalid arguments\n");
				return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
