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

	if (check_args(argc, argv) == -1)
		return (1);
	if (global_args_init(argv, &args) == -1)
		return (1);
	printf("global_args_init done\n");
	philosophing(&args);
	return (0);
}
