/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:06:57 by sbart             #+#    #+#             */
/*   Updated: 2022/07/08 19:20:55 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h> 
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_data
{
	int				numb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	long long		time_start;
	pid_t			*p_id;
	sem_t			*sem_for_forks;
	sem_t			*sem_for_print;
	sem_t			*sem_for_time;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				complete;
	t_data			*link;
	long long		time_last_eat;
}					t_philo;

int			ft_print_error(char *str);
int			ft_atoi(const char *string);
int			init_structures(t_data *data);
long long	current_time(void);
void		show_info(char *string, t_philo *philo, long long time, sem_t *sem);
void		*philo_begin(void *philo_data);
void		my_sleep(int time);
void		create_semaphore(t_data *data);
void		destroy_semaphore(t_data *data);
int			free_data(t_data *data);

#endif