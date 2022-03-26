/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:34:28 by ppiques           #+#    #+#             */
/*   Updated: 2022/03/21 10:34:28 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct  s_philo
{
	pthread_t	thread_id;
	int			philo_id;
	t_args		*args;
}				t_philo;

typedef struct	s_args
{
	int	philo_nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	optional;
	pthread_mutex_t	thinking;
	pthread_mutex_t	eating;
	pthread_mutex_t	forks[200];
	t_philo	philosophers[200];

}				t_args;

//  utils
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);

// check_args.c
int			check_args(int argc, const char **argv);

// parsing.c
int			global_args_init(const char **argv, t_args *args);
int			check_global_args(t_args *args);
int			mutex_init(t_args *args);


#endif
