/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:34:30 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/21 10:34:30 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, const char **argv)
{
	t_args	args;

	if (check_args(argc, argv) == 1)
		return (1);
	if (global_args_init(argv, &args) == -1)
		return (1);
	printf("philo_nbr = %d\n", args.philo_nbr);
	printf("time_to_die = %d\n", args.time_to_die);
	return (0);
}
