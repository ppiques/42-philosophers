/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:34:30 by ppiques           #+#    #+#             */
/*   Updated: 2022/04/10 20:04:04 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, const char **argv)
{
	t_args	args;

	if (check_args(argc, argv) == -1)
		return (1);
	if (global_args_init(argv, &args) == -1)
		return (1);
	if (args.philo_nbr == 1)
	{
		lone_dinner(&args);
		return (0);
	}
	philosophing(&args);
	return (0);
}
