/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:26:51 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/26 17:08:34 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long int	ret;

	i = 0;
	minus = 1;
	ret = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 0)
		ret = 10 * ret + str[i++] - '0';
	if (str[i] != 0 && ft_isdigit(str[i]) == 0)
		return (0);
	ret = ret * minus;
	return (ret);
}
