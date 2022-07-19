/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:57 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 18:08:41 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h> 
# include <unistd.h>

typedef struct s_data
{
	int				numb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long long		time_start;
	pthread_mutex_t	*mutex_for_philo;
	pthread_mutex_t	mutex_for_printf;
	pthread_mutex_t	mutex_for_show_info;
	pthread_mutex_t	mutex_for_check_dead;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				complete;
	int				count_eat;
	t_data			*link;
	long long		time_last_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}					t_philo;

int			ft_print_error(char *str);
int			ft_atoi(const char *string);
int			init_structures(t_data *data);
long long	current_time(void);
void		free_philos(t_philo *philo, pthread_mutex_t *mutex_for_philo);
int			program_fail(t_data *data);
void		show_info(char *string, t_philo *philo, long long time, \
				pthread_mutex_t mutex);
void		*philo_begin(void *philo_data);
void		my_sleep(int time);
void		destroy_mutex(t_data *data);

#endif