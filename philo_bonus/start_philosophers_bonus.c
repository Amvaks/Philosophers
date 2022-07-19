/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:18:42 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 18:30:40 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_dead(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->link->sem_for_time);
		if (current_time() - philo->time_last_eat > philo->link->time_to_die)
		{
			show_info("0", philo, current_time() - philo->link->time_start, \
					philo->link->sem_for_print);
			exit (1);
		}
		sem_post(philo->link->sem_for_time);
	}
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		philo[i].id = i + 1;
		philo[i].link = data;
		philo[i].complete = 0;
		i++;
	}
}

void	create_process(t_philo *philo, t_data *data)
{
	pthread_t	philo_thread;
	int			i;

	i = 0;
	data->time_start = current_time();
	while (i < data->numb_philo)
	{
		data->p_id[i] = fork();
		if (data->p_id[i] == -1)
		{
			ft_print_error("Fork failed.");
			return ;
		}
		else if (!data->p_id[i])
		{
			pthread_create(&philo_thread, NULL, philo_begin, (void *)&philo[i]);
			pthread_detach(philo_thread);
			check_dead(&philo[i]);
			return ;
		}
		i++;
	}
}

int	init_structures(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * data->numb_philo);
	if (!philo)
		return (ft_print_error("Memory allocation error."));
	init_philo(philo, data);
	create_semaphore(data);
	create_process(philo, data);
	waitpid(-1, NULL, 0);
	destroy_semaphore(data);
	free(philo);
	return (0);
}
