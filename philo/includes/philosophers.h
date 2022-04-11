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
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t			thread_id;
	int					philo_id;
	int					right_fork;
	int					left_fork;
	int					fed;
	long long int		last_meal;
	struct s_args		*args;
}				t_philo;

typedef struct s_args
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				optional;
	int				full;
	int				death;
	long long int	startup_time;
	pthread_mutex_t	printing;
	pthread_mutex_t	eating;
	pthread_mutex_t	dead;
	pthread_mutex_t	mutex_full;
	pthread_mutex_t	forks[200];
	t_philo			philosophers[200];

}				t_args;

//  utils
int				ft_isdigit(int c);
long int		ft_atoi(const char *str);
int				death_checker(t_args *args);
int				full_checker(t_args *args);

// actions.c
void			print_action(t_args *args, int id, char *action);
void			meal(t_philo *philo);
void			post_meal(t_args *args, t_philo *philo);

// check_args.c
int				check_args(int argc, const char **argv);

// cleaner.c
void			thread_cleaner(t_args *args, t_philo *philo);

// nurse.c
void			nurse(t_args *a, t_philo *p);
void			nurse_funeral(t_args *args, t_philo *philo);

// parsing.c
int				global_args_init(const char **argv, t_args *args);
int				check_global_args(t_args *args);
int				mutex_init(t_args *args);
int				philosophers_init(t_args *args);

// philosophing.c
int				philosophing(t_args *args);
void			*routine(void *temp_philosopher);
int				lone_dinner(t_args *args);
void			*alone(void *temp_philosopher);

// timer.c
long long int	timer(void);
void			ft_usleep(t_args *args);
void			waiting(long long time_to_wait, t_args *args);

#endif
