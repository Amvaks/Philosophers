/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:18:42 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 18:09:05 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_complete(t_philo *philo, t_data *data)
{
	int	i;
	int	philo_complete;

	i = 0;
	philo_complete = 0;
	while (i < data->numb_philo)
	{
		philo_complete += philo[i].complete;
		i++;
	}
	if (philo_complete == data->numb_philo)
		return (1);
	return (0);
}

void	check_dead(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->numb_philo)
		{
			pthread_mutex_lock(&data->mutex_for_check_dead);
			if ((current_time() - philo[i].time_last_eat) > data->time_to_die)
			{
				show_info("0", &philo[i], current_time() - data->time_start, \
						data->mutex_for_printf);
				return ;
			}
			if (data->times_must_eat > 0)
			{
				if (check_complete(philo, data))
					return ;
			}
			pthread_mutex_unlock(&data->mutex_for_check_dead);
			usleep(1000);
			i++;
		}
	}
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		pthread_mutex_init(&data->mutex_for_philo[i], NULL);
		philo[i].id = i + 1;
		philo[i].count_eat = 0;
		philo[i].link = data;
		philo[i].complete = 0;
		philo[i].left_fork = &data->mutex_for_philo[i];
		philo[i].right_fork = &data->mutex_for_philo[(i + 1) % \
				data->numb_philo];
		i++;
	}
}

int	create_threads(t_philo *philo, t_data *data)
{
	pthread_t	*philo_threads;
	int			i;

	i = 0;
	philo_threads = (pthread_t *)malloc(sizeof(pthread_t) * data->numb_philo);
	if (!philo_threads)
		return (ft_print_error("Memory allocation error."));
	while (i < data->numb_philo)
	{
		pthread_create(&philo_threads[i], NULL, philo_begin, (void *)&philo[i]);
		pthread_detach(philo_threads[i]);
		i++;
	}
	check_dead(data, philo);
	destroy_mutex(data);
	free(philo_threads);
	return (0);
}

int	init_structures(t_data *data)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->numb_philo);
	if (!philo)
		return (ft_print_error("Memory allocation error."));
	data->mutex_for_philo = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			data->numb_philo);
	if (!data->mutex_for_philo)
	{
		free_philos(philo, data->mutex_for_philo);
		return (ft_print_error("Memory allocation error."));
	}
	pthread_mutex_init(&data->mutex_for_printf, NULL);
	pthread_mutex_init(&data->mutex_for_show_info, NULL);
	pthread_mutex_init(&data->mutex_for_check_dead, NULL);
	init_philo(philo, data);
	data->time_start = current_time();
	if (create_threads(philo, data) < 0)
	{
		free_philos(philo, data->mutex_for_philo);
		return (-1);
	}
	free_philos(philo, data->mutex_for_philo);
	return (0);
}
